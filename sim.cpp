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

  top.p_clk.set<bool>(true);
  top.step();
  for(int cycle=0;cycle<1000;++cycle){
    uint32_t pc = top.p_pc.get<uint32_t>();
    const uint32_t instruction = ((uint32_t) contents[pc+0]) << 0
                               | ((uint32_t) contents[pc+1]) << 8
                               | ((uint32_t) contents[pc+2]) << 16
                               | ((uint32_t) contents[pc+3]) << 24;
    top.p_instruction.set<uint32_t>(instruction);

    top.p_clk.set<bool>(false);
    top.step();
    top.debug_eval();

    std::cout << "INSTRUCTION: " << std::setfill('0') << std::setw(8) << std::hex << top.p_instruction.get<uint32_t>() << " ";
    std::cout << "RA: " << top.memory_p_r[1].get<uint32_t>() << " ";
    std::cout << "R[1] (RA): " << std::hex << top.memory_p_r[1].get<uint32_t>() << " ";
    // std::cout << "RD: " << std::hex << top.p_decoder_2e_rd.get<uint32_t>() << " ";
    std::cout << "B: " << std::hex << top.p_decoder_2e_branch.get<bool>() << " ";
    std::cout << "BT: " << std::hex << top.p_branch__taken.get<bool>() << " ";
    // std::cout << "JAL: " << std::hex << top.p_decoder_2e_jal.get<bool>() << " ";
    std::cout << "DM: " << std::hex << top.p_decoder_2e_mem.get<bool>() << " ";
    // std::cout << "DMW: " << std::hex << top.p_decoder_2e_mem__write.get<bool>() << " ";
    std::cout << "PC: " << std::hex << pc << std::endl;

    uint32_t addr = top.p_addr.get<uint32_t>() << 2;
    uint16_t sel = top.p_sel.get<uint16_t>();
    if (top.p_mem.get<bool>() && top.p_mem__write.get<bool>()) {
      uint32_t data__out = top.p_data__out.get<uint32_t>();

      if (addr == 1024) {
        // std::cout << "LED: " << std::hex << data__out << std::endl;
      } else if (addr == 1028) {
        std::cout << char(data__out) << std::flush;
      } else if (2048 <= addr && addr < 2048 + 1024) {
        // std::cout << "MEM STORE " << std::hex << addr << " " << std::hex << sel << std::endl;
        if (sel & 1) ram[addr + 0 - 2048] = data__out;
        if (sel & 2) ram[addr + 1 - 2048] = data__out >> 8;
        if (sel & 4) ram[addr + 2 - 2048] = data__out >> 16;
        if (sel & 8) ram[addr + 3 - 2048] = data__out >> 24;
      }
    }
    if (top.p_mem.get<bool>() && !top.p_mem__write.get<bool>()) {
      if (addr == 1032) {
        top.p_data__in.set<uint32_t>(getch());
        top.p_read__ack.set<bool>(true);
      } else if (2048 <= addr && addr < 2048 + 1024) {
        uint32_t ram_word =
            (((uint32_t) ram[addr + 0 - 2048]))
          | (((uint32_t) ram[addr + 1 - 2048]) << 8)
          | (((uint32_t) ram[addr + 2 - 2048]) << 16)
          | (((uint32_t) ram[addr + 3 - 2048]) << 24);

        // std::cout << "MEM READ " << std::hex << addr << " " << std::hex << ram_word << std::endl;
        top.p_data__in.set<uint32_t>(
          ram_word
        );
        top.p_read__ack.set<bool>(true);
      } else {
        top.p_read__ack.set<bool>(false);
      }
    } else {
      top.p_read__ack.set<bool>(false);
    }

    top.p_clk.set<bool>(true);
    top.step();
    top.debug_eval();
  }
}
