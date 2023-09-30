`timescale 1ns / 1ps
module meow;

reg clk;

wire [31:0] instruction;
wire [31:0] pc;

wire [31:0] data_in = ram_select ? ram_out : uart_rx_select ? {24'b0, uart_rx_data} : 0;
wire [31:0] data_out;
wire [31:0] addr;

wire [31:0] ram_out;

wire [7:0] uart_rx_data = "b";

wire mem_write;
wire mem;

wire ram_select = 256 <= addr && addr < 256 + 256;
wire led_select = addr == 1024;
wire uart_tx_select = addr == 1028;
wire uart_rx_select = addr == 1032;

rom rom(pc, instruction);

wire read_ack = ram_select ? ram_read_ack : uart_rx_select ? uart_rx_ack : 0;
wire ram_read_ack = 0;
wire uart_rx_ack = 1;

ram ram(
    .read_addr(addr[7:2]),
    .data_out(ram_out),
    .mem_read(mem && !mem_write && ram_select),
    .read_ack(ram_read_ack),
    .read_clk(clk),

    .write_addr(addr[7:2]),
    .data_in(data_out),
    .mem_write(mem && mem_write && ram_select),
    .write_clk(clk)
);

furv core(
    .instruction(instruction), 
    .pc(pc), 

    .data_in(data_in), 
    .data_out(data_out), 
    .addr(addr), 
    .mem(mem), 
    .mem_write(mem_write), 
    .read_ack(read_ack),

    .clk(clk)
);

initial begin
    #5 clk = 0;
    forever
        #5 clk = ~clk;
end

initial #1000 $finish;

always @(posedge(clk)) begin
    if (mem && mem_write && led_select) begin
        $display ("data_out=%b, addr=%b", data_out, addr); 
    end else if (mem && mem_write && uart_tx_select) begin
        $display ("%c", data_out); 
    end
end

endmodule
