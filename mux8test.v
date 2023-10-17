module _MUX8(input [7:0] x, input [2:0] sel, output reg y);

always @* begin
  y = x[sel];
  // case (sel)
  //   0: y = x[0];
  //   1: y = x[1];
  //   2: y = x[2];
  //   3: y = x[3];
  //   4: y = x[4];
  //   5: y = x[5];
  //   6: y = x[6];
  //   7: y = x[7];
  // endcase
end

endmodule