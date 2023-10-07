(* top *)
module top(
    input clk,
    output [5:0] leds,
    output uart_tx,
    input uart_rx,

    input key
);

wire [31:0] pc;
wire [31:0] instruction;

wire [31:0] data_in = ram_stb ? ram_out : uart_rx_stb ? {24'b0, uart_rx_data} : 0;
wire [31:0] data_out;
wire [29:0] addr;
wire [3:0] sel;

wire [31:0] ram_out;

wire we;
wire ack = uart_rx_ack | uart_tx_ack | ram_ack | led_ack;
wire uart_rx_ack;
wire uart_tx_ack;
wire ram_ack;
wire led_ack;

wire cyc;

wire tx_available;
wire [7:0] tx_data;

wire [7:0] uart_rx_data;

wire ram_stb = 2048 <= {addr, 2'b00} && {addr, 2'b00} < 2048 + 1024;
wire led_stb = {addr, 2'b00} == 1024;
wire uart_tx_stb = {addr, 2'b00} == 1028;
wire uart_rx_stb = {addr, 2'b00} == 1032;

wire sysclk = pll_out & lock;
wire pll_out;
wire lock;
rPLL #( // For GW1NR-9 C6/I5
  .FCLKIN("27"),
  .IDIV_SEL(8), // -> PFD = 3 MHz (range: 3-400 MHz)
  .FBDIV_SEL(7), // -> CLKOUT = 24 MHz (range: 3.125-500 MHz)
  .ODIV_SEL(32) // -> VCO = 768 MHz (range: 400-1000 MHz)
) pll (.CLKOUTP(), .CLKOUTD(), .CLKOUTD3(), .RESET(1'b0), .RESET_P(1'b0), .CLKFB(1'b0), .FBDSEL(6'b0), .IDSEL(6'b0), .ODSEL(6'b0), .PSDA(4'b0), .DUTYDA(4'b0), .FDLY(4'b0),
  .CLKIN(clk), // 27 MHz
  .CLKOUT(pll_out), // 24 MHz
  .LOCK(lock)
);

uart #(.CLOCKS_PER_BIT(104), .TX_FIFO(16), .RX_FIFO(16)) uart(
    .clk(sysclk),
    .uart_tx(uart_tx),
    .uart_rx(uart_rx),

    .tx_available(cyc && we && uart_tx_stb),
    .tx_data(data_out[7:0]),
    .tx_ack(uart_tx_ack),

    .rx_data(uart_rx_data),
    .rx_pop(cyc && !we && uart_rx_stb),
    .rx_ack(uart_rx_ack)
);

ram ram(
    .clk(sysclk),
    .addr(addr[7:0]),
    .data_in(data_out),
    .data_out(ram_out),
    .we(we),
    .sel(sel),
    .stb(ram_stb),
    .ack(ram_ack),
    .cyc(cyc)
);

led led(
    .clk(sysclk),
    .data_in(data_out),
    .we(we),
    .stb(led_stb),
    .ack(led_ack),
    .cyc(cyc),

    .leds(leds)
);

rom rom(
    .pc(pc), 
    .instruction(instruction)
);

furv furv(
    .instruction(instruction),
    .pc(pc),

    .data_in(data_in),
    .data_out(data_out),
    .addr(addr),
    .sel(sel),
    .mem_write(we),
    .mem(cyc),
    .ack(ack),
    .clk(sysclk)
);


endmodule
