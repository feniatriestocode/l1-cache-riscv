`include "constants.v"
`include "config.vh"

module cpu(input clock, 
		   input reset, 
		   output overflow);

pipeline pipeline(.clock(clock), 
				  .reset(reset), 
				  .overflow(overflow));

// caches instantiated here
// to be implemented !!!!!!!!!!!!!!!!!!!!!
Icache Icache();
Dcache Dcache();
endmodule