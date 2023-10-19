module _MUX8(input [7:0] x, input [2:0] sel, output reg y);

always @* begin
  y = x[sel];
end

endmodule