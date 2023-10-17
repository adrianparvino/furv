(* top *)
module top(
input [1:0] byte_addr,
input [3:0] data_in,
output reg [3:0] data_in_
);

always @* begin
  data_in_[3:2] = data_in[3:2];
  data_in_[1] = byte_addr[1] ? data_in[3] : data_in[1];
  data_in_[0] = byte_addr[1] ? (byte_addr[0] ? data_in[3] : data_in[2]) : (byte_addr[0] ? data_in[1] : data_in[0]);
end

endmodule
