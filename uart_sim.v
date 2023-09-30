module uart#(
  parameter CLOCKS_PER_BIT = 312,
  parameter TX_FIFO = 8,
  parameter RX_FIFO = 8
)(
    input clk,
    output reg uart_tx = 1,
    input uart_rx,

    input tx_available,
    input [7:0] tx_data,
    output tx_ack,

    output [7:0] rx_data,
    input rx_pop,
    output reg rx_ack = 0
);

always @(posedge clk) begin
  if (tx_available) $display("%c", tx_data);
end

assign rx_data = "b";
always @(posedge clk) begin
  rx_ack <= rx_pop;
end  

endmodule
