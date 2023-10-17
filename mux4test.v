module _MUX4(input [3:0] x, input [1:0] sel, output reg y);

always @* begin
  // y = x[sel];
  case (sel)
    0: y = x[0];
    1: y = x[1];
    2: y = x[2];
    3: y = x[3];
  endcase
end

endmodule