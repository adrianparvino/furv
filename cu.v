module cu (
  input [31:0] ra,
  input [31:0] rb,

  input lt,
  input invert,
  input unsigned_comparison,

  output reg out = 0
);

always @* begin
  casez ({lt, invert, unsigned_comparison})
  3'b00?: out = ra == rb;
  3'b01?: out = ra != rb;
  3'b100: out = $signed(ra) < $signed(rb);
  3'b101: out = ra < rb;
  3'b110: out = $signed(ra) >= $signed(rb);
  3'b111: out = ra >= rb;
  endcase
end

endmodule
