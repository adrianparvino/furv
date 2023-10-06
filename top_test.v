(* top *)
module top(
    input clk,
    output [5:0] led,
    output uart_tx,
    input uart_rx,

    input key
);

rom rom(.pc(0), .instruction());

endmodule
