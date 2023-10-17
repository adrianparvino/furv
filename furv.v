module furv(
    input [31:0] instruction,
    output reg [31:0] pc = 0,

    input [31:0] data_in,
    output reg [31:0] data_out = 0,
    output reg [29:0] addr = 0,
    output reg [3:0] sel = 0,
    output reg mem = 0,
    output reg mem_write = 0,
    input ack,

    input clk
);

integer i;

reg [31:0] r [31:0];
initial for (i=0;i<32;i=i+1) r[i] = 32'b0;

wire [4:0] decoder_ra;
wire [4:0] decoder_rb;
wire [4:0] rd;
wire [1:0] wb;

wire lui;
wire jalr;

wire arith_mode;
wire decoder_logic_alt;
wire [2:0] decoder_funct3;
wire lt;
wire invert_comparison;
wire unsigned_comparison;

wire arith_unsigned_compare;
wire arith_signed_compare;

wire [31:0] arith_out;
wire [31:0] logic_out;
wire [31:0] shifter_out;
wire comparison_out;

wire [31:0] decoder_imm;

wire sel_ra_pc;
wire sel_rb_imm;

wire decoder_mem;
wire decoder_mem_write;
wire [1:0] decoder_mem_width;
wire decoder_mem_unsigned;

wire branch;
wire jal;
wire u;

immdecoder immdecoder(
  .instruction(fetched_instruction),
  .imm(decoder_imm)
);

alu alu(
  .ra(ra),
  .rb(rb),

  .arith_mode(arith_mode),
  .logic_alt(logic_alt),
  .funct3(funct3),

  .arith_unsigned_compare(arith_unsigned_compare),
  .arith_signed_compare(arith_signed_compare),

  .arith_out(arith_out),
  .logic_out(logic_out),
  .shifter_out(shifter_out),
);

cu cu(
  .ra(ra),
  .rb(rb),

  .lt(lt),
  .invert(invert_comparison),
  .unsigned_comparison(unsigned_comparison),

  .out(comparison_out)
);

decoder decoder(
  .instruction(fetched_instruction),

  .ra(decoder_ra),
  .rb(decoder_rb),
  .rd(rd),
  .wb(wb),
  .lui(lui),
  .jalr(jalr),

  .sel_ra_pc(sel_ra_pc),
  .sel_rb_imm(sel_rb_imm),

  .mem(decoder_mem),
  .mem_write(decoder_mem_write),
  .mem_width(decoder_mem_width),
  .mem_unsigned(decoder_mem_unsigned),

  .branch(branch),
  .jal(jal),
  .u(u),

  .arith_mode(arith_mode),
  .logic_alt(decoder_logic_alt),
  .funct3(decoder_funct3),
  .lt(lt),
  .invert_comparison(invert_comparison),
  .unsigned_comparison(unsigned_comparison)
);

reg [15:0] word_in = 0;
reg [7:0] byte_in = 0;
reg branch_taken;
reg [31:0] branch_pc;
reg pc_ra_imm;
wire [31:0] adjacent_pc = pc + 4;

wire [31:0] agu = ra + imm;
wire [1:0] byte_addr = agu[1:0];

always @* begin
  word_in = byte_addr[1] ? data_in[31:16] : data_in[15:0];
  byte_in = byte_addr[1] ? (byte_addr[0] ? data_in[31:24] : data_in[23:16]) : (byte_addr[0] ? data_in[15:8] : data_in[7:0]);
end

reg [31:0] fetched_instruction;
localparam IF = 0;
localparam DE = 1;
localparam EXM = 2;
localparam WB = 3;
reg [1:0] stage = 0;

reg [31:0] ra;
reg [31:0] rb;

reg [31:0] alu_results;
reg [31:0] imm;
reg [1:0] mem_width;
reg mem_internal;
reg mem_write_internal;

reg logic_alt;
reg [2:0] funct3;

reg [255:0] pipeline_alu_results;

always @(posedge clk) begin
  // $display("PC=%x SRP=%x SRI=%x IMM=%x AO=%x PIM=%x A5=%x S0=%x", pc, sel_ra_pc, sel_rb_imm, imm, arith_out, pc + imm, r[15], r[8]);
  // $display("PC=%x A4=%x A5=%x JAL=%b CO=%b", pc, r[14], r[15], jal, comparison_out);
  case (stage)
    IF: begin
      fetched_instruction <= instruction;
      stage <= DE;
    end
    DE: begin
      ra <= r[decoder_ra];
      rb <= sel_rb_imm ? decoder_imm : r[decoder_rb];
      imm <= decoder_imm;
      mem_width <= decoder_mem_width;
      pc_ra_imm <= jal && jalr;
      mem_internal <= decoder_mem;
      mem_write_internal <= decoder_mem_write;
      logic_alt <= decoder_logic_alt;
      funct3 <= decoder_funct3;

      stage <= EXM;
    end
    EXM: begin
      mem <= mem_internal;
      mem_write <= mem_write_internal;

      addr <= agu[31:2];

      data_out[7:0] <= rb[7:0];
      data_out[15:8] <= byte_addr[0] ? rb[7:0] : rb[15:8];
      data_out[23:16] <= byte_addr[1] ? rb[7:0] : rb[23:16];
      data_out[31:24] <= byte_addr[1] ? (byte_addr[0] ? rb[7:0] : rb[15:8]) : (byte_addr[0] ? rb[23:16] : rb[31:24]);

      sel[0] <= mem_width == 2 || byte_addr == 0;
      sel[1] <= mem_width == 2 || (mem_width == 1 && byte_addr == 0) || byte_addr == 1;
      sel[2] <= mem_width == 2 || byte_addr == 2;
      sel[3] <= mem_width == 2 || (mem_width == 1 && byte_addr == 2) || byte_addr == 3;

      branch_taken <= branch && (jal || comparison_out);
      branch_pc <= (pc_ra_imm ? ra : pc) + imm;

      pipeline_alu_results <= {
        logic_out,
        logic_out,
        shifter_out,
        logic_out,
        {31'b0, arith_unsigned_compare},
        {31'b0, arith_signed_compare},
        shifter_out,
        arith_out
      };

      stage <= WB;
    end WB: begin
      if (!mem || ack) begin
        if (rd != 0) begin
          casez ({mem_width, wb})
          4'b0000: begin
            r[rd] <= {{24{!decoder_mem_unsigned & byte_in[7]}}, byte_in};
          end
          4'b0100: begin
            r[rd] <= {{16{!decoder_mem_unsigned & word_in[15]}}, word_in};
          end
          4'b1000: begin 
            r[rd] <= data_in;
          end
          4'b??01: begin 
            r[rd] <= adjacent_pc;
          end
          4'b??10: begin 
            r[rd] <= pipeline_alu_results[32*funct3+:32];
          end
          4'b??11: begin 
            r[rd] <= lui ? imm : pc + imm;
          end
          endcase
        end

        case (branch_taken)
        0: pc <= adjacent_pc;
        1: pc <= branch_pc;
        endcase

        stage <= IF;

        mem <= 0;
        mem_write <= 0;
      end
    end
  endcase
end

endmodule
