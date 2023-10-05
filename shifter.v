module shifter (
  input [31:0] ra,
  input [31:0] rb,

  input logic_alt,
  input [2:0] funct3,
  output [31:0] out
);

wire [4:0] rb_ = rb;

wire [31:0] sext = {{31{logic_alt & ra[31]}}, 1'b0} << ~rb_;
assign out = funct3[2] ? (ra >> rb_) | sext : ra << rb_;

endmodule
