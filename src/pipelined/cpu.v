//`include "constants.v"
//`include "config.vh"

module cpu(input clock, 
		   input reset,
		   // imem
		   output ImemRen,
           output [(`IMEM_BLOCK_ADDR_SIZE-1):0] IblockAddr,
           input [(`IBLOCK_SIZE_BITS-1):0] ImemDout,
           input ImemReadReady,
           // dmem
           output DmemRen, 
           output DmemWen,
           output [(`DMEM_BLOCK_ADDR_SIZE-1):0] DblockAddress, 
           output [(`DBLOCK_SIZE_BITS-1):0] DmemDin,
           input DmemReadReady, 
           input DmemWriteDone,
           input [(`DBLOCK_SIZE_BITS-1):0] DmemDout);     

// pipeline signals
wire dcacheStall, icacheStall;
wire pipelineDRen, pipelineDWen, pipelineIRen;
wire [`DADDR_SIZE-1:0] pipelineDAddr;
wire [`IADDR_SIZE-1:0] pipelineIAddr;
wire [`DWORD_SIZE-1:0] byteSelectVector;
wire [`DWORD_SIZE_BITS-1:0] pipelineDataIn, pipelineDataOut;
wire [`IWORD_SIZE_BITS-1:0] pipelineInstrIn;

wire [`IMEM_BLOCK_ADDR_SIZE-1:0] iblockAddr;
wire [`DMEM_BLOCK_ADDR_SIZE-1:0] dblockAddr;

// icache signals
wire icacheRen, icacheMemWen, icacheHit;
wire [`IBLOCK_SIZE_BITS-1:0] icacheDin, icacheDout;

// dcache signals
wire dcacheRen, dcacheWen, dcacheMemWen, dcacheHit, dcacheDirtyBit;
wire [`DBLOCK_SIZE_BITS-1:0] dcacheDin, dcacheDout;
wire [`DBLOCK_SIZE-1:0] bytesAccess;


pipeline pipeline(.clock(clock), 
				  .reset(reset),

                  // inputs from cache controllers
		          .dcache_stall(dcacheStall),
                  .icache_stall(icacheStall),
                  .data_input(pipelineDataIn),
                  .instruction_input(pipelineInstrIn),
				  
                  // outputs for cache controllers
                  .dcache_ren(pipelineDRen),
				  .dcache_wen(pipelineDWen),
                  .icache_ren(pipelineIRen),
				  .dcache_addr(pipelineDAddr),
                  .icache_addr(pipelineIAddr),
				  .byteSelectVector(byteSelectVector),
                  .data_output(pipelineDataOut));

icache_controller icachecontroller2check(
                        .clock(clock),
                        .reset(reset),
                        
                        // pipeline inputs
                        .ren(pipelineIRen),
                        .addr(pipelineIAddr),

                        // cache inputs
                        .cacheHit(icacheHit),
                        .cacheDout(icacheDout),
                        
                        // memory inputs
                        .memReadReady(ImemReadReady),
                        .memDout(ImemDout),

                        // pipeline outputs
                        .stall(icacheStall),
                        .dout(pipelineInstrIn),
                        
                        //both cache and memory output
                        .BlockAddr(iblockAddr),

                        // cache outputs
                        .cacheRen(icacheRen),
                        .cacheMemWen(icacheMemWen),
                        .cacheDin(icacheDin),

                        // memory outputs
                        .memRen(ImemRen));

Icache_SRAM Icache(.clk(clock), 
                   .rst(reset),
                   .ren(icacheRen), 
                   .memWen(icacheMemWen),
                   .blockAddr(iblockAddr), 
                   .dataIn(icacheDin), 
                   .hit(icacheHit),
                   .dataOut(icacheDout));




dcache_controller Dcntr(.clock(clock),
                        .reset(reset),
                        
                        // pipeline inputs
                        .ren(pipelineDRen),
                        .wen(pipelineDWen),
                        .addr(pipelineDAddr),
                        .byteSelectVector(byteSelectVector),
                        .din(pipelineDataOut),

                        // cache inputs
                        .cacheHit(dcacheHit),
                        .cacheDirtyBit(dcacheDirtyBit),
                        .cacheDout(dcacheDout),
                        
                        // memory inputs
                        .memReadReady(DmemReadReady),
                        .memWriteDone(DmemWriteDone),
                        .memDout(DmemDout),
                        
                        // pipeline outputs
                        .stall(dcacheStall),
                        .dout(pipelineDataIn),
                        
                        //both cache and memory output
                        .BlockAddr(dblockAddr),
                        
                        // cache outputs
                        .cacheRen(dcacheRen),
                        .cacheWen(dcacheWen),
                        .cacheMemWen(dcacheMemWen),
                        .cacheBytesAccess(bytesAccess),
                        .cacheDin(dcacheDin),
                        
                        // memory outputs
                        .memRen(DmemRen),
                        .memWen(DmemWen),
                        .memDin(DmemDin));

Dcache_SRAM Dcache(.clk(clock), 
                   .rst(reset),
                   .ren(dcacheRen), 
                   .wen(dcacheWen), 
                   .memWen(dcacheMemWen),
                   .bytesAccess(bytesAccess),
                   .blockAddr(dblockAddr), 
                   .dataIn(dcacheDin), 
                   .hit(dcacheHit),
                   .dirtyBit(dcacheDirtyBit),
                   .dataOut(dcacheDout));

endmodule
