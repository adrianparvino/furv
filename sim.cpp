#include <iostream>
#include <iomanip>
#include <fstream>
#include "furv.cpp"
#include <unistd.h>
#include <termios.h>

using namespace std;

char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    std::cin >> buf;
    // old.c_lflag |= ICANON;
    // old.c_lflag |= ECHO;
    // if(tcsetattr(0, TCSADRAIN, &old) < 0)
    //     perror("tcsetattr ~ICANON");
    // std::cout << char(buf) << std::flush;
    return buf;
 }

char ram[1024];

int main()
{
  cxxrtl_design::p_furv top;

  std::ifstream stream("count.bin", std::ios::in | std::ios::binary);
  std::vector<uint8_t> contents((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

  top.p_clk.set<bool>(false);
  top.step();
  for(int cycle=0;cycle<1000;++cycle){
    bool ack = 0;
    uint32_t pc = top.p_pc.get<uint32_t>();
    const uint32_t instruction = ((uint32_t) contents[pc+0]) << 0
                               | ((uint32_t) contents[pc+1]) << 8
                               | ((uint32_t) contents[pc+2]) << 16
                               | ((uint32_t) contents[pc+3]) << 24;
    top.p_instruction.set<uint32_t>(instruction);
    top.step();

    uint32_t addr = top.p_addr.get<uint32_t>() << 2;
    uint16_t sel = top.p_sel.get<uint16_t>();
    if (top.p_mem.get<bool>() && top.p_mem__write.get<bool>()) {
      uint32_t data__out = top.p_data__out.get<uint32_t>();

      if (addr == 1024) {
        std::cout << "LED: " << std::hex << data__out << std::endl;

        ack = 1;
      } else if (addr == 1028) {
        std::cout << char(data__out) << std::flush;

        ack = 1;
      } else if (2048 <= addr && addr < 2048 + 1024) {
        std::cout << "MEM STORE " << std::hex << addr << " DATA: " << std::hex << data__out << " " << std::hex << sel << std::endl;
        if (sel & 1) ram[addr + 0 - 2048] = data__out;
        if (sel & 2) ram[addr + 1 - 2048] = data__out >> 8;
        if (sel & 4) ram[addr + 2 - 2048] = data__out >> 16;
        if (sel & 8) ram[addr + 3 - 2048] = data__out >> 24;

        ack = 1;
      }
    }

    if (top.p_mem.get<bool>() && !top.p_mem__write.get<bool>()) {
      if (addr == 1032) {
        top.p_data__in.set<uint32_t>(getch());

        ack = 1;
      } else if (2048 <= addr && addr < 2048 + 1024) {
        uint32_t ram_word =
            (((uint32_t) ram[addr + 0 - 2048]))
          | (((uint32_t) ram[addr + 1 - 2048]) << 8)
          | (((uint32_t) ram[addr + 2 - 2048]) << 16)
          | (((uint32_t) ram[addr + 3 - 2048]) << 24);

        std::cout << "MEM READ " << std::hex << addr << " " << std::hex << ram_word << " " << std::hex << sel << std::endl;
        top.p_data__in.set<uint32_t>(
          ram_word
        );

        ack = 1;
      }
    }

    top.step();
    top.debug_eval();
    // // std::cout << "BYTE_IN: " << std::setfill('0') << std::setw(2) << std::hex << top.p_byte__in.get<uint16_t>() << " ";
    // // std::cout << "BADDR: " << std::setfill('0') << std::setw(2) << std::hex << top.p_byte__addr.get<uint32_t>() << " ";
    // // // std::cout << "INSTRUCTION: " << std::setfill('0') << std::setw(8) << std::hex << top.p_instruction.get<uint32_t>() << " ";
    // // // std::cout << "RA: " << top.memory_p_r[1].get<uint32_t>() << " ";
    // std::cout << "R[16] (A6): " << std::hex << top.memory_p_r[0x10].get<uint32_t>() << " ";
    // std::cout << "R[10] (A0): " << std::hex << top.memory_p_r[10].get<uint32_t>() << " ";
    // std::cout << "RD: " << std::hex << top.p_decoder_2e_rd.get<uint32_t>() << " ";
    // // std::cout << "RE: " << std::hex << top.memory_p_r[15].get<uint32_t>() << " ";
    // // std::cout << "WB: " << std::hex << top.p_wb.get<uint32_t>() << " ";
    // std::cout << "ALU_RESULTS: " << std::hex << top.p_alu__results.get<uint32_t>() << " ";
    // std::cout << "IMM: " << std::hex << top.p_alu__results.get<uint32_t>() << " ";
    // // // std::cout << "B: " << std::hex << top.p_decoder_2e_branch.get<bool>() << " ";
    // // // std::cout << "CALC_ACK: " << std::hex << ack << " ";
    // // // std::cout << "CALC_ACK2: " << std::hex << (top.p_mem.get<bool>() && addr == 1024) << " ";
    // // // std::cout << "ACK: " << std::hex << top.p_ack.get<bool>() << " ";
    // // // std::cout << "ADDR: " << std::hex << top.p_addr.get<uint32_t>() << " ";
    // // // std::cout << "BT: " << std::hex << top.p_branch__taken.get<bool>() << " ";
    // // // // // std::cout << "JAL: " << std::hex << top.p_decoder_2e_jal.get<bool>() << " ";
    // // // std::cout << "DM: " << std::hex << top.p_mem.get<bool>() << " ";
    // // // std::cout << "DMW: " << std::hex << top.p_mem__write.get<bool>() << " ";
    // std::cout << "DIN: " << std::hex << top.p_data__in.get<uint32_t>() << " ";
    // std::cout << "BIN: " << std::hex << top.p_byte__in.get<uint32_t>() << " ";
    // // std::cout << "SRBI: " << std::hex << top.p_sel__rb__imm.get<uint16_t>() << " ";
    // // std::cout << "DRB: " << std::setw(8) << std::hex << top.p_decoder__rb.get<uint32_t>() << " ";
    // std::cout << "MEM: " << std::setw(8) << std::hex << top.p_mem.get<uint32_t>() << " ";
    // std::cout << "MEM_WIDTH: " << std::setw(8) << std::hex << top.p_mem__width.get<uint32_t>() << " ";
    // std::cout << "PC: " << std::hex << pc << std::endl;
    // // top.step();
    // // top.debug_eval();

    top.p_ack.set<bool>(ack);
    top.p_clk.set<bool>(true);

    top.step();
    top.debug_eval();

    top.p_clk.set<bool>(false);
    top.step();
    top.debug_eval();
  }
}
