module alu #(
  parameter WIDTH = 32
) (
  input [WIDTH-1:0] ra,
  input [WIDTH-1:0] rb,
  input [WIDTH-1:0] rca,
  input [WIDTH-1:0] rcb,

  input arith_mode,
  input logic_alt,
  input [2:0] funct3,
  input lt,
  input invert_comparison,
  input unsigned_comparison,

  output arith_unsigned_compare,
  output arith_signed_compare,

  output [WIDTH-1:0] arith_out,
  output reg [WIDTH-1:0] logic_out = 0,
  output comparison_out
);

wire [WIDTH-1:0] lu_out;
reg [2*WIDTH-2:0] shifter;
reg ignore;

au #(.WIDTH(WIDTH)) au(
  .ra(ra),
  .rb(rb),
  .mode(arith_mode),
  .out(arith_out),
  .unsigned_compare(arith_unsigned_compare),
  .signed_compare(arith_signed_compare)
);

lu #(.WIDTH(WIDTH)) lu(
  .ra(ra),
  .rb(rb),
  .alt(logic_alt),
  .funct3(funct3),
  .out(lu_out)
);

cu #(.WIDTH(WIDTH)) cu(
  .ra(rca),
  .rb(rcb),

  .lt(lt),
  .invert(invert_comparison),
  .unsigned_comparison(unsigned_comparison),

  .out(comparison_out)
);

always @* begin
  shifter = {{WIDTH{logic_alt & ra[WIDTH-1]}}, ra} << (funct3[2] ? ~rb[$clog2(WIDTH)-1:0] : rb[$clog2(WIDTH)-1:0]);

  logic_out = funct3[1:0] == 1 ? (funct3[2] ? shifter[2*WIDTH-2:WIDTH-1] : shifter[WIDTH-1:0]) : lu_out;
end

endmodule