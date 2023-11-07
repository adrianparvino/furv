module furv_rf(
  input [4:0] de_rs1_index,
  input [4:0] de_rs2_index,
  input [4:0] de_lock_rd,

  output [31:0] rf_rs1,
  output [31:0] rf_rs2,
  output rf_rs1_ready,
  output rf_rs2_ready,

  input [4:0] wb_rel_rd,
  input [31:0] wb_rd_value,
  input wb_rd_ready,

  input stall_i,

  input clk
);

integer i;

reg [31:0] r [31:0];
initial for (i=0;i<32;i=i+1) r[i] = 32'b0;

assign rf_rs1 = r[de_rs1_index];
assign rf_rs2 = r[de_rs2_index];

reg [31:0] r_used = 0;

assign rf_rs1_ready = !r_used[de_rs1_index];
assign rf_rs2_ready = !r_used[de_rs2_index];

always @(posedge clk) begin
  for (i = 1; i < 32; i=i+1) begin
    if (wb_rd_ready && wb_rel_rd == i)
      r_used[i] <= 0;
    else if (!stall_i && de_lock_rd == i)
      r_used[i] <= 1;
  end

  if (wb_rd_ready && wb_rel_rd != 0) begin
    r[wb_rel_rd] <= wb_rd_value;
  end
end

endmodule
