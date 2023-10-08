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
      unsigned_compare = 'x;
      signed_compare = 'x;
    end
    1: begin
      out = ra - rb;
      unsigned_compare = ra < rb;
      signed_compare = $signed(ra) < $signed(rb);
    end
  endcase
end

endmodule
