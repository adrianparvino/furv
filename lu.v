module lu (
  input [31:0] ra,
  input [31:0] rb,

  input alt,
  input [2:0] funct3,

  output reg [31:0] out
);

always @* begin
  case (funct3[1:0])
    0: out = ra ^ rb;
    1: out = ra;
    2: out = ra | rb;
    3: out = ra & rb;
  endcase
end

endmodule
