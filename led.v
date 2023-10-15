module led(
  input clk,
  input [31:0] data_in,
  input we,
  input stb,
  output ack,
  input cyc,

  output reg [5:0] leds = 6'b111111
);

assign ack = cyc && stb && we;

always @(posedge clk) begin
    if (ack) begin
        leds <= ~data_in[4:0];
    end
end


endmodule
