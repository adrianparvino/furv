module cu (
  input [31:0] ra,
  input [31:0] rb,

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
