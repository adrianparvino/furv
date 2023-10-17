module shifter (
  input [31:0] ra,
  input [4:0] rb,
  input signd,
  input lsl,
  output reg [31:0] out
);

reg [31:0] ra_;
reg [31:0] shift16;

integer i;

always @* begin
  if (lsl)
    ra_ = ra;
  else
    for(i=0;i<32;i=i+1)
        ra_[i] = ra[32-1-i];

  if (lsl)
    out = shift16;
  else
    for(i=0;i<32;i=i+1)
        out[i] = shift16[32-1-i];
end

always @* begin
  shift16 = {signd & ra[31], ra} >>> rb;
end

endmodule
