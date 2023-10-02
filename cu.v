module cu #(
  parameter WIDTH = 32
) (
  input [WIDTH-1:0] ra,
  input [WIDTH-1:0] rb,

  input lt,
  input invert,
  input unsigned_comparison,

  output reg out = 0
);

wire [WIDTH-1:0] ra_ = {!unsigned_comparison ^ ra[WIDTH-1], ra[WIDTH-2:0]};
wire [WIDTH-1:0] rb_ = {!unsigned_comparison ^ rb[WIDTH-1], rb[WIDTH-2:0]};

wire lt_result = ra_ < rb_;
wire eq_result = ~|(ra_ - rb_);

always @* begin
  out = invert ^ (lt ? lt_result : eq_result);
end

endmodule
