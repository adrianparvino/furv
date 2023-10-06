module uart#(
  parameter CLOCKS_PER_BIT = 104,
  parameter TX_FIFO = 16,
  parameter RX_FIFO = 16
)(
    input clk,
    output reg uart_tx = 1,
    input uart_rx,

    input tx_available,
    input [7:0] tx_data,
    output tx_ack,

    output [7:0] rx_data,
    input rx_pop,
    output rx_ack
);

localparam HALF_CLOCKS_PER_BIT = CLOCKS_PER_BIT/2;

reg [7:0] tx_shift_register = 0;
reg [7:0] tx_shift_registers [TX_FIFO-1:0];
reg [$clog2(TX_FIFO):0] tx_read_i = 0;
reg [$clog2(TX_FIFO):0] tx_write_i = 0;

reg [$clog2(CLOCKS_PER_BIT)-1:0] tx_divider = 0;
wire [$clog2(CLOCKS_PER_BIT)-1:0] tx_next = tx_divider + 1;

reg [3:0] tx_state = 14;

wire tx_full = (tx_read_i ^ tx_write_i) == TX_FIFO;
wire tx_sample = tx_next == CLOCKS_PER_BIT;

assign tx_ack = tx_available && !tx_full;

always @(posedge clk) begin
  if (tx_ack) begin
    tx_shift_registers[tx_write_i[$clog2(TX_FIFO)-1:0]] <= tx_data;
    tx_write_i <= tx_write_i + 1;
  end
end

always @(posedge clk) begin
  if (tx_state == 14) begin
    if (tx_read_i != tx_write_i) begin
      tx_divider <= 0;
      tx_state <= 15;
      tx_shift_register <= tx_shift_registers[tx_read_i[$clog2(TX_FIFO):0]];
      tx_read_i <= tx_read_i + 1;
    end
  end else begin
    if (tx_sample) begin
      if (tx_state == 15) begin
        uart_tx <= 1'b0;
      end else begin
        uart_tx <= tx_shift_register[0];

        tx_shift_register <= {1'b1, tx_shift_register[7:1]};
      end

      tx_state <= tx_state + 1;
    end

    tx_divider <= tx_sample ? 0 : tx_next;
  end
end

reg [7:0] rx_shift_register = 0;
reg [7:0] rx_shift_registers [RX_FIFO-1:0];
reg [$clog2(RX_FIFO):0] rx_read_i = 0;
reg [$clog2(RX_FIFO):0] rx_write_i = 0;

reg [$clog2(CLOCKS_PER_BIT)-1:0] rx_divider = 0;
wire [$clog2(CLOCKS_PER_BIT)-1:0] rx_next = rx_divider + 1;
wire rx_sample = rx_next == CLOCKS_PER_BIT;

reg [3:0] rx_state = 9;

wire rx_empty = rx_read_i == rx_write_i;
wire rx_full = (rx_read_i ^ rx_write_i) == RX_FIFO;

assign rx_data = rx_shift_registers[rx_read_i[$clog2(RX_FIFO)-1:0]];
assign rx_ack = rx_pop && !rx_empty;

always @(posedge clk) begin
  if (rx_ack) begin
    rx_read_i <= rx_read_i + 1;
  end
end

always @(posedge clk) begin
  if (rx_state == 9) begin
    if (uart_rx == 0) begin
      rx_divider <= HALF_CLOCKS_PER_BIT;
      rx_state <= 15;
    end
  end else begin
    if (rx_divider == 0) begin
      if (rx_state < 8) begin
        rx_shift_register <= {uart_rx, rx_shift_register[7:1]};
      end else if (rx_state == 8) begin
        if (!rx_full) begin
          rx_shift_registers[rx_write_i[$clog2(RX_FIFO)-1:0]] <= rx_shift_register;
          rx_write_i <= rx_write_i + 1;
        end
      end

      rx_state <= rx_state + 1;
    end

    rx_divider <= rx_sample ? 0 : rx_next;
  end
end

endmodule
