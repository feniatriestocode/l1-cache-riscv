/*IMPLEMENTATION OF A PARAMETRIZED INSTRUCTION MEMORY ON RISC-V*/

////`timescale 1ns / 1ps

//`include "../include/constants.vh"
//`include "../common/counter.v" //sees it from makefile supposedly
//`include "../../testbench/config.vh" //sees it from makefile supposedly

// If ren stays up then the next read has no delay !

// Read: Input: reset = 1'b1, ren = 1'b1, block_address = address of block in memory.
//       Output: when ready = 1'b1: dout = desired block data.
// No Write.
module Imem(input clock, reset, 
			input ren, 
			input [(`IMEM_BLOCK_ADDR_SIZE-1):0] block_address, 		// in blocks
			output reg ready,
			output reg [(`IBLOCK_SIZE_BITS-1):0] dout);

/****** SIGNALS ******/
reg [(`IWORD_SIZE_BITS-1):0] data [0:(`IMEM_SIZE_BLOCKS-1)][`IBLOCK_SIZE_WORDS-1:0];

wire delayed, counter_reset;
wire [(`IMEM_DELAY_CNTR_SIZE-1):0] delay_counter;

integer i;

/****** LOGIC ******/
assign counter_reset = ~reset || ~ren;

counter #(.size(`IMEM_DELAY_CNTR_SIZE)) delay_cntr (.reset(counter_reset), .clk(clock), .hold(delayed), .counter(delay_counter));

assign delayed = &delay_counter;

always @ (posedge clock or negedge reset)
begin
	if(~reset)
	begin
		ready <= 1'b0;
	end
	else
	begin
		ready <= delayed;
	end
end

always @(delayed or block_address) begin
    if (delayed) begin
        dout = {`IBLOCK_SIZE_BITS{1'b0}};  // Initialize dout
        for (i = 0; i < `IBLOCK_SIZE_WORDS; i = i + 1) begin
            dout[(i+1)*`IWORD_SIZE_BITS-1 -: `IWORD_SIZE_BITS] = data[block_address][i];
        end
    end else begin
        dout = {`IBLOCK_SIZE_BITS{1'b0}};
    end
end

/****** SIMULATION ******/
initial $readmemh("test.hex", data);
endmodule