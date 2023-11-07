module cu (
  input [31:0] ra,
  input [31:0] rb,

  input lt,
  input invert,
  input unsigned_comparison,

  output reg out = 0
);

always @* begin
  casez ({lt, unsigned_comparison})
  2'b00: out = ra == rb;
  2'b01: out = 1;
  2'b10: out = $signed(ra) < $signed(rb);
  2'b11: out = ra < rb;
  endcase

  if (invert) out = !out;
end

endmodule
