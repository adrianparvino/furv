module au #(
  parameter WIDTH = 32
) (
  input [WIDTH-1:0] ra,
  input [WIDTH-1:0] rb,

  input mode,

  output reg [WIDTH-1:0] out,
  output reg unsigned_compare,
  output reg signed_compare
);

always @* begin
  case (mode)
    0: begin
      out = ra + rb;
      unsigned_compare = 0;
    end
    1: begin
      out = ra - rb;
      unsigned_compare = ra < rb;
    end
  endcase
  signed_compare = (ra[WIDTH - 1] && !rb[WIDTH - 1]) || ((ra[WIDTH - 1] == rb[WIDTH - 1]) && out[WIDTH - 1]);
end

endmodule
