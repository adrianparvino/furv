module shifter #(
  parameter WIDTH = 32
) (
  input [(WIDTH-1):0] ra,
  input [(WIDTH-1):0] rb,

  input logic_alt,
  input [2:0] funct3,
  output reg [(WIDTH-1):0] out
);

integer i;

wire [4:0] rb_ = rb;

reg [31:0] ra_;
reg [31:0] shift_out;

always @* begin
  if (funct3[2])
    ra_ = ra;
  else
    for(i=0;i<WIDTH;i=i+1)
        ra_[i] = ra[WIDTH-1-i];

  if (funct3[2])
    out = shift_out;
  else
    for(i=0;i<WIDTH;i=i+1)
        out[i] = shift_out[WIDTH-1-i];
end

always @* begin
  shift_out = {logic_alt & ra_[WIDTH-1], ra_} >>> rb_;
end

endmodule
