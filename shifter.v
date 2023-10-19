module shifter (
  input [31:0] ra,
  input [31:0] rb,

  input logic_alt,
  input shift_right,
  output reg [31:0] out
);

integer i;

always @* begin
  if (shift_right)
    out = shift16;
  else
    for(i=0;i<32;i=i+1)
        out[i] = shift16[32-1-i];
end

genvar j;

wire [31:0] shift3i0;
wire [31:0] shift3i1;
wire [31:0] shift3;
generate
  for (j = 0; j < 32 - 3; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) LOW(.F(shift3i0[j]), .I0(rb[0]), .I1(ra[j + 1]), .I2(ra[j]));
    LUT3 #(.INIT(8'b11011000)) HIGH(.F(shift3i1[j]), .I0(rb[0]), .I1(ra[j + 3]), .I2(ra[j + 2]));
  end

  for (j = 32 - 3; j < 32 - 2; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) LOW1(.F(shift3i0[j]), .I0(rb[0]), .I1(ra[j + 1]), .I2(ra[j]));
    LUT4 #(.INIT(16'b1000111110000000)) HIGH1(.F(shift3i1[j]), .I0(logic_alt), .I1(ra[32 - 1]), .I2(rb[0]), .I3(ra[j + 2]));
  end
  for (j = 32 - 2; j < 32 - 1; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) LOW2(.F(shift3i0[j]), .I0(rb[0]), .I1(ra[j + 1]), .I2(ra[j]));
    LUT2 #(.INIT(4'b1000)) HIGH2(.F(shift3i1[j]), .I0(logic_alt), .I1(ra[32 - 1]));
  end
  for (j = 32 - 1; j < 32 - 0; j = j + 1) begin
    LUT4 #(.INIT(16'b1000111110000000)) LOW3(.F(shift3i0[j]), .I0(logic_alt), .I1(ra[32 - 1]), .I2(rb[0]), .I3(ra[j]));
    LUT2 #(.INIT(4'b1000)) HIGH3(.F(shift3i1[j]), .I0(logic_alt), .I1(ra[32 - 1]));
  end

  for (j = 0; j < 32; j = j + 1) begin
    MUX2_LUT5 A(.O(shift3[j]), .I0(shift3i0[j]), .I1(shift3i1[j]), .S0(rb[1]));
  end
endgenerate

wire [31:0] shift12i0;
wire [31:0] shift12i1;
wire [31:0] shift12;
generate
  for (j = 0; j < 32 - 12; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) LOW(.F(shift12i0[j]), .I0(rb[2]), .I1(shift3[j + 4]), .I2(shift3[j]));
    LUT3 #(.INIT(8'b11011000)) HIGH(.F(shift12i1[j]), .I0(rb[2]), .I1(shift3[j + 12]), .I2(shift3[j + 8]));
  end

  for (j = 32 - 12; j < 32 - 8; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) LOW1(.F(shift12i0[j]), .I0(rb[2]), .I1(shift3[j + 4]), .I2(shift3[j]));
    LUT4 #(.INIT(16'b1000111110000000)) HIGH1(.F(shift12i1[j]), .I0(logic_alt), .I1(ra[32 - 1]), .I2(rb[2]), .I3(shift3[j + 8]));
  end
  for (j = 32 - 8; j < 32 - 4; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) LOW2(.F(shift12i0[j]), .I0(rb[2]), .I1(shift3[j + 4]), .I2(shift3[j]));
    LUT2 #(.INIT(4'b1000)) HIGH2(.F(shift12i1[j]), .I0(logic_alt), .I1(ra[32 - 1]));
  end
  for (j = 32 - 4; j < 32 - 0; j = j + 1) begin
    LUT4 #(.INIT(16'b1000111110000000)) LOW3(.F(shift12i0[j]), .I0(logic_alt), .I1(ra[32 - 1]), .I2(rb[2]), .I3(shift3[j]));
    LUT2 #(.INIT(4'b1000)) HIGH3(.F(shift12i1[j]), .I0(logic_alt), .I1(ra[32 - 1]));
  end

  for (j = 0; j < 32; j = j + 1) begin
    MUX2_LUT5 A(.O(shift12[j]), .I0(shift12i0[j]), .I1(shift12i1[j]), .S0(rb[3]));
  end
endgenerate

wire [31:0] shift16;
generate
  for (j = 0; j < 32 - 16; j = j + 1) begin
    LUT3 #(.INIT(8'b11011000)) A(.F(shift16[j]), .I0(rb[4]), .I1(shift12[j + 16]), .I2(shift12[j]));
  end

  for (j = 32 - 16; j < 32; j = j + 1) begin
    LUT4 #(.INIT(16'b1000111110000000)) A(.F(shift16[j]), .I0(logic_alt), .I1(ra[32 - 1]), .I2(rb[4]), .I3(shift12[j]));
  end
endgenerate

endmodule
