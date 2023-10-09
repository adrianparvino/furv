module alu (
  input [31:0] ra,
  input [31:0] rb,
  input [31:0] rca,
  input [31:0] rcb,

  input arith_mode,
  input logic_alt,
  input [2:0] funct3,
  input lt,
  input invert_comparison,
  input unsigned_comparison,

  output arith_unsigned_compare,
  output arith_signed_compare,

  output [31:0] arith_out,
  output reg [31:0] logic_out = 0,
  output comparison_out
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
  .out(lu_out)
);

cu cu(
  .ra(rca),
  .rb(rcb),

  .lt(lt),
  .invert(invert_comparison),
  .unsigned_comparison(unsigned_comparison),

  .out(comparison_out)
);

shifter shifter(
  .ra(ra),
  .rb(rb),

  .logic_alt(logic_alt),
  .funct3(funct3),
  .out(shifter_out)
);

always @* begin
  logic_out = funct3[1:0] == 1 ? shifter_out : lu_out;
end

endmodule