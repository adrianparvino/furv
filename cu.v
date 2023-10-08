module cu #(
  parameter WIDTH = 32
) (
  input [WIDTH-1:0] ra,
  input [WIDTH-1:0] rb,

  input lt,
  input invert,
  input unsigned_comparison,

  output reg out = 0
);

wire lt_result = unsigned_comparison ? ra < rb : $signed(ra) < $signed(rb);
wire eq_result = ra == rb;

always @* begin
  out = invert ^ (lt ? lt_result : eq_result);
end

endmodule
