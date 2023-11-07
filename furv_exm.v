module furv_exm(
  input [31:0] alu_a,
  input [31:0] alu_b,
  input [4:0] rd,
  input alu_sel_logic,
  input [1:0] alu_op,
  input [31:0] alu_rs1,
  input [31:0] alu_rs2,
  input [1:0] wb_sel,
  input branch,
  input mem,
  input mem_write,
  input [1:0] mem_width,
  input mem_unsigned,
  input reverse_wb,
  input lt,
  input invert_comparison,
  input unsigned_comparison,

  output reg exm_mem = 0,
  output reg exm_mem_write,
  output reg [3:0] exm_sel,
  output reg [29:0] exm_addr,
  output reg [31:0] exm_data_out,
  output reg [1:0] exm_wb_sel,
  output reg [1:0] exm_mem_width,
  output reg exm_mem_unsigned,
  output reg [1:0] exm_byte_addr,

  output reg [31:0] exm_alu_results,
  output reg [31:0] exm_shifter_results,
  output reg [31:0] exm_adjacent_pc,
  output reg [31:0] exm_u_results,
  output reg [4:0] exm_rd,
  output reg exm_reverse_wb,

  output reg exm_branch_calculated = 0,
  output reg exm_branch_taken = 0,
  output reg [31:0] exm_branch_pc,

  input stall_i,
  output reg stall_o,

  input valid_i,
  output reg valid_o = 0,

  input clk
);

wire [31:0] alu_out;
wire [31:0] arith_out;
wire [31:0] shifter_out;

alu alu(
  .ra(alu_a),
  .rb(alu_b),

  .sel_logic(alu_sel_logic),
  .op(alu_op),

  .arith_out(arith_out),
  .alu_out(alu_out)
);

shifter shifter(
  .ra(alu_a),
  .rb(alu_b),
  .logic_alt(alu_op[0]),

  .out(shifter_out)
);

wire comparison_out;

cu cu(
  .ra(alu_rs1),
  .rb(alu_rs2),

  .lt(lt),
  .invert(invert_comparison),
  .unsigned_comparison(unsigned_comparison),

  .out(comparison_out)
);

wire branch_taken = comparison_out;

always @* begin
  stall_o = stall_i;
end

always @(posedge clk) begin
  if (!stall_i) begin
    valid_o <= valid_i;

    exm_branch_calculated <= valid_i && branch;
    exm_branch_taken <= valid_i && branch && branch_taken;

    exm_branch_pc <= arith_out;

    exm_sel[0] <= mem_width == 2 || arith_out[1:0] == 0;
    exm_sel[1] <= mem_width == 2 || (mem_width == 1 && arith_out[1:0] == 0) || arith_out[1:0] == 1;
    exm_sel[2] <= mem_width == 2 || arith_out[1:0] == 2;
    exm_sel[3] <= mem_width == 2 || (mem_width == 1 && arith_out[1:0] == 2) || arith_out[1:0] == 3;

    exm_data_out[7:0] <= alu_rs2[7:0];
    exm_data_out[15:8] <= alu_out[0] ? alu_rs2[7:0] : alu_rs2[15:8];
    exm_data_out[23:16] <= alu_out[1] ? alu_rs2[7:0] : alu_rs2[23:16];
    exm_data_out[31:24] <= alu_out[1] ? (alu_out[0] ? alu_rs2[7:0] : alu_rs2[15:8]) : (alu_out[0] ? alu_rs2[23:16] : alu_rs2[31:24]);

    exm_rd <= rd;
    exm_alu_results <= alu_out;
    exm_shifter_results <= shifter_out;
    exm_wb_sel <= wb_sel;
    exm_reverse_wb <= reverse_wb;

    exm_mem <= valid_i && mem;
    exm_mem_write <= mem_write;
    exm_mem_width <= mem_width;
    exm_mem_unsigned <= mem_unsigned;
    exm_addr <= arith_out[31:2];
    exm_byte_addr <= arith_out[1:0];
  end
end

endmodule
