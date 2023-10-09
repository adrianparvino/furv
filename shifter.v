module shifter (
  input [31:0] ra,
  input [31:0] rb,

  input logic_alt,
  input [2:0] funct3,
  output reg [31:0] out
);

integer i;

wire [4:0] rb_ = rb;
reg [31:0] ra_;

always @* begin
  if (funct3[2])
    ra_ = ra;
  else
    for(i=0;i<32;i=i+1)
        ra_[i] = ra[32-1-i];

  if (funct3[2])
    out = shift16;
  else
    for(i=0;i<32;i=i+1)
        out[i] = shift16[32-1-i];
end

genvar j;

wire [31:0] shift1;
generate
  for (j = 0; j < 32 - 1; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift1[j]), .I0(ra_[j]), .I1(ra_[j + 1]), .I2(rb[0]));
  end

  for (j = 32 - 1; j < 32; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift1[j]), .I0(ra_[j]), .I1(logic_alt & ra_[32-1]), .I2(rb[0]));
  end
endgenerate

wire [31:0] shift2;
generate
  for (j = 0; j < 32 - 2; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift2[j]), .I0(shift1[j]), .I1(shift1[j + 2]), .I2(rb[1]));
  end

  for (j = 32 - 2; j < 32; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift2[j]), .I0(shift1[j]), .I1(logic_alt & ra_[32-1]), .I2(rb[1]));
  end
endgenerate

wire [31:0] shift4;
generate
  for (j = 0; j < 32 - 4; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift4[j]), .I0(shift2[j]), .I1(shift2[j + 4]), .I2(rb[2]));
  end

  for (j = 32 - 4; j < 32; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift4[j]), .I0(shift2[j]), .I1(logic_alt & ra_[32-1]), .I2(rb[2]));
  end
endgenerate

wire [31:0] shift8;
generate
  for (j = 0; j < 32 - 8; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift8[j]), .I0(shift4[j]), .I1(shift4[j + 8]), .I2(rb[3]));
  end

  for (j = 32 - 8; j < 32; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift8[j]), .I0(shift4[j]), .I1(logic_alt & ra_[32-1]), .I2(rb[3]));
  end
endgenerate

wire [31:0] shift16;
generate
  for (j = 0; j < 32 - 16; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift16[j]), .I0(shift8[j]), .I1(shift8[j + 16]), .I2(rb[4]));
  end

  for (j = 32 - 16; j < 32; j = j + 1) begin
    LUT3 #(.INIT(8'b11001010)) A(.F(shift16[j]), .I0(shift8[j]), .I1(logic_alt & ra_[32-1]), .I2(rb[4]));
  end
endgenerate

endmodule
