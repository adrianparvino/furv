module alu (
  input [31:0] ra,
  input [31:0] rb,

  input sel_logic,
  input [1:0] op,

  output [31:0] arith_out,
  output reg [31:0] alu_out
);

wire [31:0] logic_out;

au au(
  .ra(ra),
  .rb(rb),
  .op(op),

  .out(arith_out)
);

lu lu(
  .ra(ra),
  .rb(rb),
  .op(op),

  .out(logic_out)
);

always @* begin
  case (sel_logic)
  0: alu_out = arith_out;
  1: alu_out = logic_out;
  endcase
end

endmodule