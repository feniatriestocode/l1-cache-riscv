`include "constants.v"
`include "counter.v"

`timescale 1ns / 1ps
// Use this for Imem too??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// If ren stays up then the next read has no delay (need fixing?) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Read:  Input: reset = 1'b1, ren = 1'b1, wen = 1'b0, block_address = address of block in memory, din = don't care.
//        Output: when ready = 1'b1: dout = desired block data, done = don't care.
// Write: Input: reset = 1'b1, ren = 1'b0, wen = 1'b1, block address = address of block in memory, din = data of block.
//        Output: ready = don't care, dout = don't care, when done = 1'b1: data is written.
module Dmem #(	parameter WORD_SIZE = 32,		// in bits
				parameter BLOCK_SIZE = 8,		// in words
			  	parameter MEM_SIZE = 32,		// in blocks
				parameter DELAY_CNTR_SIZE = 4) 	// in bits, (delay = (DELAY_CNTR_SIZE ** 2) in cycles)
		(	input clock, reset, 
			input ren, wen,
			input [($clog2(MEM_SIZE)-1):0] block_address, 		// in blocks
			input [((WORD_SIZE*BLOCK_SIZE)-1):0] din,
			output reg ready, done,								// if not that then what??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			output [((WORD_SIZE*BLOCK_SIZE)-1):0] dout);

/****** SIGNALS ******/
reg [((WORD_SIZE*BLOCK_SIZE)-1):0] data [0:MEM_SIZE-1];
reg [((WORD_SIZE*BLOCK_SIZE)-1):0] temp_din;
reg flag;

wire delayed;
wire [(DELAY_CNTR_SIZE-1):0] delay_counter;
wire temp_ready, temp_done;

/****** LOGIC ******/
assign counter_reset = ~reset || (~wen && ~ren) || (wen && ren);

counter #(.size(DELAY_CNTR_SIZE)) delay_cntr (.reset(counter_reset), .clk(clock), .hold(delayed), .cntr(delay_counter));

assign delayed = &delay_counter;

assign temp_ready = delayed && ren && ~wen;
assign temp_done = delayed && ~ren && wen;

always @ (posedge clock or negedge reset) // is this synthesizable??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
begin
	ready <= temp_ready;
	done <= temp_done;
end

// read
assign dout = (temp_ready) ? data[block_address] : {(WORD_SIZE*BLOCK_SIZE){1'b0}};

// write
always @ (posedge clock or negedge reset)
begin
	if(~reset || ~wen || ren)
	begin
		temp_din <= {(WORD_SIZE*BLOCK_SIZE){1'b0}};
		flag <= 1'b0;
	end
	else
	begin
		if(~flag)
		begin
			temp_din <= din;
			flag <= 1'b1;
		end
	end
end

always @ (posedge clock or negedge reset)
begin 
	if(temp_done)
	begin
		data[block_address] <= temp_din;
	end
end

/****** SIMULATION ******/
initial $readmemh("test.hex", data);

always @(ren or wen)
begin
	if (ren & wen)
		$display ("\nMemory ERROR (time %0d): ren and wen both active!\n", $time);
end

endmodule