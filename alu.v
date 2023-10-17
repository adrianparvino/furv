module alu (
  input [31:0] ra,
  input [31:0] rb,

  input arith_mode,
  input logic_alt,
  input [2:0] funct3,

  output arith_unsigned_compare,
  output arith_signed_compare,

  output [31:0] arith_out,
  output [31:0] logic_out,
  output [31:0] shifter_out
);

wire [31:0] lu_out;
wire [31:0] shifter_out;
reg ignore;

au au(
  .ra(ra),
  .rb(rb),
  .mode(arith_mode),
  .out(arith_out),
  .unsigned_compare(arith_unsigned_compare),
  .signed_compare(arith_signed_compare)
);

lu lu(
  .ra(ra),
  .rb(rb),
  .alt(logic_alt),
  .funct3(funct3),
  .out(logic_out)
);

shifter shifter(
  .ra(ra),
  .rb(rb),

  .logic_alt(logic_alt),
  .shift_right(funct3[2]),
  .out(shifter_out)
);

endmodule