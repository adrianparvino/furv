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

always @* begin
  if (funct3[2])
    ra_ = ra;
  else
    for(i=0;i<WIDTH;i=i+1)
        ra_[i] = ra[WIDTH-1-i];

  if (funct3[2])
    out = shift16;
  else
    for(i=0;i<WIDTH;i=i+1)
        out[i] = shift16[WIDTH-1-i];
end

genvar j;

wire [(WIDTH - 1):0] shift1;
generate
  for (j = 0; j < WIDTH - 1; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift1[j]), .I0(ra_[j]), .I1(ra_[j + 1]), .I2(rb[0]));
  end

  for (j = WIDTH - 1; j < WIDTH; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift1[j]), .I0(ra_[j]), .I1(logic_alt & ra_[WIDTH-1]), .I2(rb[0]));
  end
endgenerate

wire [(WIDTH - 1):0] shift2;
generate
  for (j = 0; j < WIDTH - 2; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift2[j]), .I0(shift1[j]), .I1(shift1[j + 2]), .I2(rb[1]));
  end

  for (j = WIDTH - 2; j < WIDTH; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift2[j]), .I0(shift1[j]), .I1(logic_alt & ra_[WIDTH-1]), .I2(rb[1]));
  end
endgenerate

wire [(WIDTH - 1):0] shift4;
generate
  for (j = 0; j < WIDTH - 4; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift4[j]), .I0(shift2[j]), .I1(shift2[j + 4]), .I2(rb[2]));
  end

  for (j = WIDTH - 4; j < WIDTH; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift4[j]), .I0(shift2[j]), .I1(logic_alt & ra_[WIDTH-1]), .I2(rb[2]));
  end
endgenerate

wire [(WIDTH - 1):0] shift8;
generate
  for (j = 0; j < WIDTH - 8; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift8[j]), .I0(shift4[j]), .I1(shift4[j + 8]), .I2(rb[3]));
  end

  for (j = WIDTH - 8; j < WIDTH; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift8[j]), .I0(shift4[j]), .I1(logic_alt & ra_[WIDTH-1]), .I2(rb[3]));
  end
endgenerate

wire [(WIDTH - 1):0] shift16;
generate
  for (j = 0; j < WIDTH - 16; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift16[j]), .I0(shift8[j]), .I1(shift8[j + 16]), .I2(rb[4]));
  end

  for (j = WIDTH - 16; j < WIDTH; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift16[j]), .I0(shift8[j]), .I1(logic_alt & ra_[WIDTH-1]), .I2(rb[4]));
  end
endgenerate

endmodule
