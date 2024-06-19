`include "../include/constants.v"
`include "../include/constants.vh"
`include "config.vh"

module toplevel(input clock, 
				input reset);
				

wire    dmem_ren, dmem_wen, dmem_ready, dmem_done;
wire [((`DBLOCK_SIZE_BITS)-1):0] dmem_block_address;
wire [((`DBLOCK_SIZE_BITS)-1):0] dmem_din;
wire [((`DBLOCK_SIZE_BITS)-1):0] dmem_dout;

wire    imem_ren, imem_ready;
wire [($clog2(`IMEM_SIZE)-1):0] imem_block_address;
wire [((`IWORD_SIZE * `IBLOCK_SIZE)-1):0] imem_dout;


cpu cpu(.clock(clock), 
		.reset(reset),
		//imem
        .imem_ren(imem_ren),
        .imem_block_address(imem_block_address),
        .imem_ready(imem_ready),
        .imem_dout(imem_dout),
        //dmem
		.dmem_ren(dmem_ren), 
        .dmem_wen(dmem_wen),
        .dmem_block_address(dmem_block_address), 
        .dmem_din(dmem_din),
        .dmem_ready(dmem_ready), 
        .dmem_done(dmem_done),
        .dmem_dout(dmem_dout));
        

// Memories

Imem Instruction_Mem(.clock(clock), 
            .reset(reset), 
			.ren(imem_ren), 
			.block_address(imem_block_address),
			.ready(imem_ready), 
            .dout(imem_dout));
            
Dmem Data_Mem(.clock(clock), 
            .reset(reset), 
			.ren(dmem_ren), 
			.wen(dmem_wen),
			.block_address(dmem_block_address), 
			.din(dmem_din),
			.ready(dmem_ready), 
			.done(dmem_done),
            .dout(dmem_dout));

endmodule
