/*IMPLEMENTATION OF A PARAMETRIZED DATA MEMORY ON RISC-V*/

////// `timescale 1ns / 1ps

`include "constants.vh"
// `include "../common/counter.v" //sees it from makefile supposedly

// If ren stays up then the next read has no delay !

// Read:  Input: reset = 1'b1, ren = 1'b1, wen = 1'b0, block_address = address of block in memory, din = don't care.
//        Output: when ready = 1'b1: dout = desired block data, done = don't care.
// Write: Input: reset = 1'b1, ren = 1'b0, wen = 1'b1, block address = address of block in memory, din = data of block.
//        Output: ready = don't care, dout = don't care, when done = 1'b1: data is written.
module Dmem(input clock, reset, 
			input ren, wen,
			input [(`DMEM_BLOCK_ADDR_SIZE-1):0] block_address, 		// in blocks
			input [(`DBLOCK_SIZE_BITS-1):0] din,
			output reg ready, done,
			output [(`DBLOCK_SIZE_BITS-1):0] dout);

/****** SIGNALS ******/
reg [(`DBLOCK_SIZE_BITS-1):0] data [0:(`DMEM_SIZE_BLOCKS-1)];
reg [(`DBLOCK_SIZE_BITS-1):0] temp_din;
reg flag;

wire delayed, counter_reset;
wire [(`DMEM_DELAY_CNTR_SIZE-1):0] delay_counter;
wire temp_ready, temp_done;

/****** LOGIC ******/
assign counter_reset = ~reset || (~wen && ~ren) || (wen && ren);

counter #(.size(`DMEM_DELAY_CNTR_SIZE)) delay_cntr (.reset(counter_reset), .clk(clock), .hold(delayed), .counter(delay_counter));

assign delayed = &delay_counter;

assign temp_ready = delayed && ren && ~wen;
assign temp_done = delayed && ~ren && wen;

always @ (posedge clock or negedge reset)
begin
	if(~reset)
	begin
		ready <= 1'b0;
		done <= 1'b0;
	end
	else
	begin
		ready <= temp_ready;
		done <= temp_done;
	end
end

// read
assign dout = (temp_ready) ? data[block_address] : {`DBLOCK_SIZE_BITS{1'b0}};

// write
always @ (posedge clock or negedge reset)
begin
	if(~reset)
	begin
		temp_din <= {`DBLOCK_SIZE_BITS{1'b0}};
		flag <= 1'b0;
	end
	else
	begin
		if(~wen || ren)
		begin
			temp_din <= {`DBLOCK_SIZE_BITS{1'b0}};
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
end

always @ (posedge clock)
begin 
	if(temp_done)
	begin
		data[block_address] <= temp_din;
	end
end

/****** SIMULATION ******/
initial $readmemh(`DATA_HEX, data);

always @(ren or wen)
begin
	if (ren & wen)
		$display ("\nMemory ERROR (time %0d): ren and wen both active!\n", $time);
end

endmodule