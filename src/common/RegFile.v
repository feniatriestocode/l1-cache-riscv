`include "constants.v"
`include "config.vh"

// Register File. Read ports: address raA, data rdA, renA
//                            address raB, data rdB, renB
//                Write port: address wa, data wd, enable wen.
module RegFile (input clock, reset,
				input [4:0] raA, raB, wa,
				input wen,
				input [31:0] wd,
				output reg[31:0] rdA, rdB);
/****** SIGNALS ******/
integer i;
reg [31:0] data[31:0];

/****** LOGIC ******/

// The register file is written at the positive edge. Make sure that bypasssing is enabled. 
always @(posedge clock or negedge reset)
begin
	if (reset == 1'b0) begin
		rdA <= 0;
		rdB <= 0;
		for (i = 0; i < 32; i = i+1)
			data[i] = i;
	end
	else begin
		rdA <= (wen == 1'b1 && wa == raA && wa != 5'b0) ? wd : data[raA];
		rdB <= (wen == 1'b1 && wa == raB && wa != 5'b0) ? wd : data[raB];
		if (wen == 1'b1 && wa != 5'b0)
			data[wa] <=  wd;
	end
end

endmodule