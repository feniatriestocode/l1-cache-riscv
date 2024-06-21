//`include "../include/constants.v"
// `include "../common/counter.v"
// `include "../include/constants.vh"
// `include "../memories/Dmem.v"
// `include "../memories/Imem.v"
// `include "cpu.v"

//`include "config.vh"

module toplevel(input clock, 
				input reset);
				
wire dmem_ren, dmem_wen, dmem_read_ready, dmem_write_done;
wire [(`DMEM_BLOCK_ADDR_SIZE-1):0] dmem_block_address;
wire [(`DBLOCK_SIZE_BITS-1):0] dmem_din;
wire [(`DBLOCK_SIZE_BITS-1):0] dmem_dout;

wire imem_ren, imem_read_ready;
wire [(`IMEM_BLOCK_ADDR_SIZE-1):0] imem_block_address;
wire [(`IBLOCK_SIZE_BITS-1):0] imem_dout;

cpu cpu(.clock(clock), 
		.reset(reset),
		//imem
        .ImemRen(imem_ren),
        .IblockAddr(imem_block_address),
        .ImemReadReady(imem_read_ready),
        .ImemDout(imem_dout),
        //dmem
		.DmemRen(dmem_ren), 
        .DmemWen(dmem_wen),
        .DblockAddress(dmem_block_address), 
        .DmemDin(dmem_din),
        .DmemReadReady(dmem_read_ready), 
        .DmemWriteDone(dmem_write_done),
        .DmemDout(dmem_dout));
        
// Memories
Imem Instruction_Mem(.clock(clock), 
                     .reset(reset), 
			         .ren(imem_ren), 
			         .block_address(imem_block_address),
			         .ready(imem_read_ready), 
                     .dout(imem_dout));

Dmem Data_Mem(.clock(clock),
              .reset(reset),
			  .ren(dmem_ren),
			  .wen(dmem_wen),
			  .block_address(dmem_block_address),
			  .din(dmem_din),
			  .ready(dmem_read_ready),
			  .done(dmem_write_done),
              .dout(dmem_dout));

endmodule
