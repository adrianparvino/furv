module ram(
  input clk,
  input [7:0] addr,
  input [31:0] data_in,
  output [31:0] data_out,
  input we,
  input [3:0] sel,
  input stb,
  output ack,
  input cyc
);

assign ack = cyc && stb;

reg [7:0] cells [1023:0];

assign data_out[0+:8] = cells[{addr, 2'h0}];
assign data_out[8+:8] = cells[{addr, 2'h1}];
assign data_out[16+:8] = cells[{addr, 2'h2}];
assign data_out[24+:8] = cells[{addr, 2'h3}];

always @(posedge clk) begin
  if (ack && we) begin
    if (sel[0]) cells[{addr, 2'h0}] <= data_in[0+:8];
    if (sel[1]) cells[{addr, 2'h1}] <= data_in[8+:8];
    if (sel[2]) cells[{addr, 2'h2}] <= data_in[16+:8];
    if (sel[3]) cells[{addr, 2'h3}] <= data_in[24+:8];
  end
end

endmodule
