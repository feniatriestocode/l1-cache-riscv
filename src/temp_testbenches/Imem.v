`timescale 1ns / 1ps

`include "constants.v"
`include "counter.v"

// If ren stays up then the next read has no delay (need fixing?) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Read: Input: reset = 1'b1, ren = 1'b1, block_address = address of block in memory.
//       Output: when ready = 1'b1: dout = desired block data.
// No Write.
module Imem #(	parameter WORD_SIZE = 32,		// in bits
				parameter BLOCK_SIZE = 8,		// in words
			  	parameter MEM_SIZE = 32,		// in blocks
				parameter DELAY_CNTR_SIZE = 4) 	// in bits, (delay = (DELAY_CNTR_SIZE ** 2) in cycles)
	    (	input clock, reset, 
			input ren, 
			input [($clog2(MEM_SIZE)-1):0] block_address, 		// in blocks // maybe full address??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			output reg ready,									// if not that then what??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			output [((WORD_SIZE*BLOCK_SIZE)-1):0] dout);

/****** SIGNALS ******/
reg [((WORD_SIZE*BLOCK_SIZE)-1):0] data [0:MEM_SIZE-1];

wire delayed;
wire [(DELAY_CNTR_SIZE-1):0] delay_counter;

/****** LOGIC ******/
assign counter_reset = ~reset || ~ren;

counter #(.size(DELAY_CNTR_SIZE)) delay_cntr (.reset(counter_reset), .clk(clock), .hold(delayed), .cntr(delay_counter));

assign delayed = &delay_counter;

always @ (posedge clock or negedge reset) // is this synthesizable??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
begin
	ready <= delayed;
end 

assign dout = delayed ? data[block_address] : {(WORD_SIZE*BLOCK_SIZE){1'b0}};

/****** SIMULATION ******/
initial $readmemh("test.hex", data);

endmodule