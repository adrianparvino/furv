module uart#(
  parameter CLOCKS_PER_BIT = 208,
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

integer i;

localparam UART_IDLE = 0;
localparam UART_START = 1;
localparam UART_RUNNING = 2;
localparam UART_STOP = 3;

localparam HALF_CLOCKS_PER_BIT = CLOCKS_PER_BIT/2;

reg [7:0] tx_shift_register;
reg [7:0] tx_shift_registers [TX_FIFO-1:0];
reg [$clog2(TX_FIFO):0] tx_read_i = 0;
reg [$clog2(TX_FIFO):0] tx_write_i = 0;

reg [$clog2(CLOCKS_PER_BIT)-1:0] tx_divider = 0;
wire [$clog2(CLOCKS_PER_BIT)-1:0] tx_next = tx_divider + 1;

reg [1:0] tx_state = UART_IDLE;
reg [2:0] tx_index = 0;

wire tx_empty = tx_read_i == tx_write_i;
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
  if (tx_sample) begin
    case (tx_state)
      UART_IDLE: begin
        uart_tx <= 1;

        if (!tx_empty) begin
          tx_state <= UART_START;
          tx_shift_register <= tx_shift_registers[tx_read_i[$clog2(TX_FIFO):0]];
          tx_read_i <= tx_read_i + 1;
        end
      end
      UART_START: begin
        uart_tx <= 0;
        tx_state <= UART_RUNNING;
      end
      UART_RUNNING: begin
        uart_tx <= tx_shift_register[tx_index];
        tx_index <= tx_index + 1;

        if (tx_index == 7) tx_state <= UART_IDLE;
      end
    endcase
  end

  tx_divider <= tx_sample ? 0 : tx_next;
end

reg [7:0] rx_shift_register = 0;
reg [7:0] rx_shift_registers [RX_FIFO-1:0];
reg [$clog2(RX_FIFO):0] rx_read_i = 0;
reg [$clog2(RX_FIFO):0] rx_write_i = 0;

reg [$clog2(CLOCKS_PER_BIT)-1:0] rx_divider = 0;
wire [$clog2(CLOCKS_PER_BIT)-1:0] rx_next = rx_divider + 1;
wire rx_sample = rx_next == CLOCKS_PER_BIT;

reg [1:0] rx_state = UART_IDLE;
reg [2:0] rx_index = 0;

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
  if (rx_state == UART_IDLE) begin
    if (uart_rx == 0) begin
      rx_divider <= HALF_CLOCKS_PER_BIT;
      rx_state <= UART_START;
    end
  end else begin
    if (rx_sample) begin
      case (rx_state)
        UART_START: begin
          rx_state <= UART_RUNNING;
        end      
        UART_RUNNING: begin
          if (rx_index == 7) rx_state <= UART_STOP;
        end      
        UART_STOP: begin
          if (!rx_full) rx_shift_registers[rx_write_i[$clog2(RX_FIFO)-1:0]] <= rx_shift_register;
          if (!rx_full) rx_write_i <= rx_write_i + 1;
          rx_state <= UART_IDLE;
        end      
      endcase
    end

    rx_divider <= rx_sample ? 0 : rx_next;
  end

  if (rx_sample) begin
    for (i = 0; i < 8; i=i+1) begin
      if (rx_index == i) rx_shift_register[i] <= uart_rx;
    end

    rx_index <= rx_state == UART_START ? 0 : rx_index + 1;
  end
end

endmodule
