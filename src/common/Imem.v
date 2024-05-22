`include "constants.v"
`include "config.vh"
`include "counter.v"


module Imem (	input clock,
				input reset, 
				input ren, 
				input  [`TEXT_BITS-3:0] addr, 
				output [31:0] dout);

/****** SIGNALS ******/
reg [31:0] data[0:2**(`TEXT_BITS-2)-1];

wire delayed;
wire [3:0] delay_counter;

/****** LOGIC ******/
counter #(.size(4)) delay_cntr (.reset(~reset), .clk(clock), .hold(delayed), .counter(delay_counter));

assign delayed = &delay_counter;

assign dout = (reset == 1 && ren == 1 && delayed == 1) ? data[addr] : 32'b0;

/****** SIMULATION ******/
`ifdef TEXT_HEX
initial $readmemh(`TEXT_HEX, data);
`endif

endmodule