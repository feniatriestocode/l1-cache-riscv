`include "constants.v"
`include "config.vh"

module Imem (input clock, reset, 
			input ren, wen, 
			input  [`TEXT_BITS-3:0] addr, 
			input [31:0] din, 
			output [31:0] dout);

/****** SIGNALS ******/
reg [31:0] data[0:2**(`TEXT_BITS-2)-1];


/****** LOGIC ******/

assign dout = (reset == 1) ? data[addr] : 32'b0;

/* Write memory in the negative edge of the clock */
always @(posedge clock)
begin
	if (wen == 1'b1 && ren==1'b0 && reset==1'b1)
		data[addr] <= din;
end

/****** SIMULATION ******/

`ifdef TEXT_HEX
initial $readmemh(`TEXT_HEX, data);
`endif

always @(ren or wen)
begin
	if (ren & wen)
		$display ("\nMemory ERROR (time %0d): ren and wen both active!\n", $time);
end

endmodule