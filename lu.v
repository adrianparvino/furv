module lu (
  input [31:0] ra,
  input [31:0] rb,
  input [1:0] op,

  output reg [31:0] out
);

always @* begin
  case (op)
    0: out = ra ^ rb;
    1: out = rb;
    2: out = ra | rb;
    3: out = ra & rb;
  endcase
end

endmodule
