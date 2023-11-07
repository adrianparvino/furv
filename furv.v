module furv(
    input [31:0] instruction,
    output [31:0] pc,

    input [31:0] data_in,
    output [31:0] data_out,
    output [29:0] addr,
    output [3:0] sel,
    output mem,
    output mem_write,
    input ack,

    input clk
);

wire [31:0] if_pc;
wire [31:0] instruction_fetched;
wire branch_calculated;
wire branch_taken;
wire [31:0] branch_pc;

wire if_stall;
wire if_valid_o;

furv_if furv_if(
  .pc(pc),
  .instruction_i(instruction),
  .if_pc(if_pc),
  .instruction(instruction_fetched),

  .branch_calculated(branch_calculated),
  .branch_taken(branch_taken),
  .branch_pc(branch_pc),

  .stall_i(if_stall),
  .stall_o(),

  .valid_i(1'b1),
  .valid_o(if_valid_o),

  .clk(clk)
);

wire [4:0] de_rs1_index;
wire [4:0] de_rs2_index;
wire [4:0] de_lock_rd;
wire [31:0] rf_rs1;
wire [31:0] rf_rs2;
wire rf_rs1_ready;
wire rf_rs2_ready;

wire [31:0] de_alu_a;
wire [31:0] de_alu_b;
wire [4:0] de_rd;
wire [1:0] de_alu_op;
wire de_alu_sel_logic;
wire [31:0] de_alu_rs1;
wire [31:0] de_alu_rs2;
wire [1:0] de_wb_sel;
wire de_branch;
wire de_mem;
wire de_mem_write;
wire [1:0] de_mem_width;
wire de_mem_unsigned;
wire de_reverse_wb;
wire de_lt;
wire de_invert_comparison;
wire de_unsigned_comparison;

wire de_stall;
wire de_valid_o;

wire [4:0] wb_rel_rd;
wire [31:0] wb_rd_value;
wire wb_rd_ready;

furv_rf furv_rf(
  .de_rs1_index(de_rs1_index),
  .de_rs2_index(de_rs2_index),
  .de_lock_rd(de_lock_rd),
  .rf_rs1(rf_rs1),
  .rf_rs2(rf_rs2),
  .rf_rs1_ready(rf_rs1_ready),
  .rf_rs2_ready(rf_rs2_ready),

  .wb_rel_rd(wb_rel_rd),
  .wb_rd_value(wb_rd_value),
  .wb_rd_ready(wb_rd_ready),

  .stall_i(if_stall),

  .clk(clk)
);

furv_de furv_de(
  .instruction(instruction_fetched),
  .pc(if_pc),

  .de_rs1_index(de_rs1_index),
  .de_rs2_index(de_rs2_index),
  .de_lock_rd(de_lock_rd),
  .rf_rs1(rf_rs1),
  .rf_rs2(rf_rs2),
  .rf_rs1_ready(rf_rs1_ready),
  .rf_rs2_ready(rf_rs2_ready),

  .de_alu_a(de_alu_a),
  .de_alu_b(de_alu_b),
  .de_rd(de_rd),
  .de_alu_sel_logic(de_alu_sel_logic),
  .de_alu_op(de_alu_op),
  .de_alu_rs1(de_alu_rs1),
  .de_alu_rs2(de_alu_rs2),
  .de_wb_sel(de_wb_sel),
  .de_branch(de_branch),
  .de_mem(de_mem),
  .de_mem_write(de_mem_write),
  .de_mem_width(de_mem_width),
  .de_mem_unsigned(de_mem_unsigned),
  .de_reverse_wb(de_reverse_wb),
  .de_lt(de_lt),
  .de_invert_comparison(de_invert_comparison),
  .de_unsigned_comparison(de_unsigned_comparison),

  .stall_i(de_stall),
  .stall_o(if_stall),

  .valid_i(if_valid_o),
  .valid_o(de_valid_o),

  .clk(clk)
);

wire [31:0] exm_alu_results;
wire [31:0] exm_shifter_results;
wire [31:0] exm_adjacent_pc;
wire [31:0] exm_u_results;
wire [4:0] exm_rd;
wire [1:0] exm_wb_sel;
wire [1:0] exm_mem_width;
wire exm_mem_unsigned;
wire [1:0] exm_byte_addr;
wire exm_reverse_wb;

wire exm_stall;
wire exm_valid_o;

furv_exm furv_exm(
  .alu_a(de_alu_a),
  .alu_b(de_alu_b),
  .rd(de_rd),
  .alu_sel_logic(de_alu_sel_logic),
  .alu_op(de_alu_op),
  .alu_rs1(de_alu_rs1),
  .alu_rs2(de_alu_rs2),
  .wb_sel(de_wb_sel),
  .branch(de_branch),
  .mem(de_mem),
  .mem_write(de_mem_write),
  .mem_width(de_mem_width),
  .mem_unsigned(de_mem_unsigned),
  .reverse_wb(de_reverse_wb),
  .lt(de_lt),
  .invert_comparison(de_invert_comparison),
  .unsigned_comparison(de_unsigned_comparison),

  .exm_mem(mem),
  .exm_mem_write(mem_write),
  .exm_mem_width(exm_mem_width),
  .exm_mem_unsigned(exm_mem_unsigned),
  .exm_sel(sel),
  .exm_addr(addr),
  .exm_data_out(data_out),
  .exm_wb_sel(exm_wb_sel),
  .exm_byte_addr(exm_byte_addr),
  .exm_reverse_wb(exm_reverse_wb),

  .exm_alu_results(exm_alu_results),
  .exm_shifter_results(exm_shifter_results),
  .exm_adjacent_pc(exm_adjacent_pc),
  .exm_u_results(exm_u_results),
  .exm_rd(exm_rd),

  .exm_branch_calculated(branch_calculated),
  .exm_branch_taken(branch_taken),
  .exm_branch_pc(branch_pc),

  .stall_i(exm_stall),
  .stall_o(de_stall),

  .valid_i(de_valid_o),
  .valid_o(exm_valid_o),

  .clk(clk)
);

furv_wb furv_wb(
  .rd(exm_rd),
  .wb_sel(exm_wb_sel),
  .mem_width(exm_mem_width),
  .mem_unsigned(exm_mem_unsigned),
  .alu_results(exm_alu_results),
  .shifter_results(exm_shifter_results),
  .adjacent_pc(exm_adjacent_pc),
  .reverse_wb(exm_reverse_wb),

  .mem(mem),
  .mem_ack(ack),
  .data_in(data_in),
  .byte_addr(exm_byte_addr),

  .wb_rel_rd(wb_rel_rd),
  .wb_rd_value(wb_rd_value),
  .wb_rd_ready(wb_rd_ready),

  .stall_i(1'b0),
  .stall_o(exm_stall),

  .valid_i(exm_valid_o),
  .valid_o(),

  .clk(clk)
);

endmodule
