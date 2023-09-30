module lu #(
  parameter WIDTH = 32
) (
  input [WIDTH-1:0] ra,
  input [WIDTH-1:0] rb,

  input alt,
  input [2:0] funct3,

  output reg [WIDTH-1:0] out
);

reg [WIDTH-1:0] bitops;
reg [2*WIDTH-2:0] shifter;

reg ignore;

always @* begin
  shifter = {{WIDTH{alt & ra[WIDTH-1]}}, ra} << (funct3[2] ? ~rb[$clog2(WIDTH)-1:0] : rb[$clog2(WIDTH)-1:0]);

  case (funct3[1:0])
    0: bitops = ra ^ rb;
    1: bitops = ra;
    2: bitops = ra | rb;
    3: bitops = ra & rb;
  endcase

  out = funct3[1:0] == 1 ? (funct3[2] ? shifter[2*WIDTH-2:WIDTH-1] : shifter[WIDTH-1:0]) : bitops;
end

endmodule
