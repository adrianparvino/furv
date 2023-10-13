module _MUX8(input [7:0] x, input [2:0] sel, output y);

wire a, b, c, d;
wire ab, cd;

LUT3 #(.INIT(8'b11001010)) A(.F(a), .I0(x[0]), .I1(x[1]), .I2(sel[0]));
LUT3 #(.INIT(8'b11001010)) B(.F(b), .I0(x[2]), .I1(x[3]), .I2(sel[0]));
LUT3 #(.INIT(8'b11001010)) C(.F(c), .I0(x[4]), .I1(x[5]), .I2(sel[0]));
LUT3 #(.INIT(8'b11001010)) D(.F(d), .I0(x[6]), .I1(x[7]), .I2(sel[0]));

MUX2_LUT5 AB(.I0(a), .I1(b), .S0(sel[1]), .O(ab));
MUX2_LUT5 CD(.I0(c), .I1(d), .S0(sel[1]), .O(cd));

MUX2_LUT6 Y(.I0(ab), .I1(cd), .S0(sel[2]), .O(y));

endmodule
