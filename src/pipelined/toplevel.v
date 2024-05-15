`include "constants.v"
`include "config.vh"

module toplevel(input clock, 
				input reset, 
				output overflow);

cpu cpu(.clock(clock), 
		.reset(reset), 
		.overflow(overflow));

// Memories

// to be implemented !!!!!!!!!!!!!!!
Imem Instruction_Mem();
Dmem Data_Mem();

endmodule