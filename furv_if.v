module furv_if(
  output reg [31:0] pc,
  input [31:0] instruction_i,
  output reg [31:0] if_pc = 0,
  output reg [31:0] instruction = 0,

  input branch_calculated,
  input branch_taken,
  input [31:0] branch_pc,

  input stall_i,
  output reg stall_o,

  input valid_i,
  output reg valid_o,

  input clk
);

reg branch_wait = 0;
reg [31:0] pc_internal = 0;

always @* begin
  case (branch_taken)
    0: pc = pc_internal;
    1: pc = branch_pc;
  endcase

  stall_o = stall_i;
end

always @(posedge clk) begin
  if (!stall_i) begin
    valid_o <= valid_i && (!branch_wait || branch_calculated);

    if_pc <= pc;
    instruction <= instruction_i;
  end

  if (!stall_i && (!branch_wait || branch_calculated)) begin
    branch_wait <= instruction_i[6];

    pc_internal <= pc + 4;
  end
end

endmodule
