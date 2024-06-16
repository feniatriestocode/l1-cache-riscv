`include "constants.v"
`include "config.vh"

module toplevel(input clock, 
				input reset);
				

wire    dmem_ren, dmem_wen, dmem_ready, dmem_done;
wire [] dmem_block_address;
wire [] dmem_din;
wire [] dmem_dout;

wire    imem_ren, imem_ready;
wire [] imem_block_address;
wire [] imem_dout;


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

// to be implemented !!!!!!!!!!!!!!!
Imem Instruction_Mem(clock(clock), 
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
