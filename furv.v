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

wire [4:0] ra;
wire [4:0] rb;
wire [4:0] rd;

wire arith_mode;
wire logic_alt;
wire [2:0] funct3;
wire lt;
wire invert_comparison;
wire unsigned_comparison;

wire arith_unsigned_compare;
wire arith_signed_compare;

wire [31:0] arith_out;
wire [31:0] logic_out;
wire comparison_out;

wire [31:0] imm;

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
  .instruction(instruction),
  .imm(imm)
);

alu #(.WIDTH(32)) alu(
  .ra(sel_ra_pc ? pc : r[ra]),
  .rb(sel_rb_imm ? imm : r[rb]),
  .rca(r[ra]),
  .rcb(r[rb]),

  .arith_mode(arith_mode),
  .logic_alt(logic_alt),
  .funct3(funct3),
  .lt(lt),
  .invert_comparison(invert_comparison),
  .unsigned_comparison(unsigned_comparison),

  .arith_unsigned_compare(arith_unsigned_compare),
  .arith_signed_compare(arith_signed_compare),

  .arith_out(arith_out),
  .logic_out(logic_out),
  .comparison_out(comparison_out)
);

decoder decoder(
  .instruction(instruction),

  .ra(ra),
  .rb(rb),
  .rd(rd),

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
  .logic_alt(logic_alt),
  .funct3(funct3),
  .lt(lt),
  .invert_comparison(invert_comparison),
  .unsigned_comparison(unsigned_comparison)
);

wire branch_taken = branch && (jal || comparison_out);
wire [31:0] adjacent_pc = pc + 4;
wire [1:0] byte_addr = arith_out[1:0];

always @* begin
  mem = decoder_mem;
  mem_write = decoder_mem_write;
  addr = arith_out[31:2];
  data_out = r[rb] << 8*byte_addr;

  case (decoder_mem_width)
  0: sel = 4'b0001 << byte_addr;
  1: sel = 4'b0011 << byte_addr;
  2: sel = 4'b1111;
  3: sel = 4'b1111;
  endcase
end

always @(posedge clk) begin
  // $display("PC=%x SRP=%x SRI=%x IMM=%x AO=%x PIM=%x A5=%x S0=%x", pc, sel_ra_pc, sel_rb_imm, imm, arith_out, pc + imm, r[15], r[8]);
  // $display("PC=%x A4=%x A5=%x JAL=%b CO=%b", pc, r[14], r[15], jal, comparison_out);
  if (!decoder_mem || ack) begin
    if (rd != 0) begin
      if ((branch && !jal) || (decoder_mem && decoder_mem_write)) begin
        // Nothing
      end else if (branch && jal) begin
        r[rd] <= adjacent_pc;
      end else if (decoder_mem && !decoder_mem_write) begin
      // $display("DIN=%x", data_in);
        case (decoder_mem_width)
        0: r[rd] <= ({data_in[8*byte_addr+:8], 24'h0} >> 24) & (decoder_mem_unsigned ? 32'hff : 32'hffffffff);
        1: r[rd] <= ({data_in[8*byte_addr+:16], 16'h0} >> 16) & (decoder_mem_unsigned ? 32'hffff : 32'hffffffff);
        2: r[rd] <= data_in;
        endcase
      end else if (u) begin
        r[rd] <= arith_out;
      end else begin
        // if (pc == 32'h50) begin
          // $display("%x %x %x", instruction, imm, funct3);
        // end
        case (funct3)
        0: r[rd] <= arith_out;
        1: r[rd] <= logic_out;
        2: r[rd] <= {31'b0, arith_signed_compare};
        3: r[rd] <= {31'b0, arith_unsigned_compare};
        4: r[rd] <= logic_out;
        5: r[rd] <= logic_out;
        6: r[rd] <= logic_out;
        7: r[rd] <= logic_out;
        endcase
      end
    end

    pc <= branch_taken ? arith_out : adjacent_pc;
  end
end

endmodule
