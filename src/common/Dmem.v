`include "constants.v"
`include "config.vh"

// Read : disable wen, enable ren, address addr, data dout
// Write: enable wen, disable ren, address addr, data din.
module Dmem (input clock, reset,
			input ren, wen,
			input [`DATA_BITS-3:0] addr,
			input [31:0] din,
			output [31:0] dout);

/****** SIGNALS ******/
reg [31:0] data[0:2**(`DATA_BITS-2)-1];


/****** LOGIC ******/

assign dout = (reset == 1) ? data[addr] : 32'b0;

/* Write memory in the negative edge of the clock */
always @(posedge clock)
begin
	if (wen == 1'b1 && ren==1'b0 && reset == 1'b1)
		data[addr] <= din;
end

/****** SIMULATION ******/

`ifdef DATA_HEX
initial $readmemh(`DATA_HEX, data);
`endif


always @(ren or wen)
begin
	if (ren & wen)
		$display ("\nMemory ERROR (time %0d): ren and wen both active!\n", $time);
end

endmodule