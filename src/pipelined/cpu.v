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
           
//dcache_controller 
wire ren, wen;
wire [(`DADDR_SIZE-1):0] addr;
wire [(`DWORD_SIZE-1):0] byteSelectVector;
wire [(`DWORD_SIZE_BITS-1):0] din;
wire cacheHit;
wire cacheDirtyBit;
wire [(`DBLOCK_SIZE_BITS-1):0] cacheDout;
wire memReadReady, memWriteDone;
wire [(`DBLOCK_SIZE_BITS-1):0] memDout;

wire stall;
wire [(`DWORD_SIZE_BITS-1):0] dout;
wire [(`DMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr;
wire cacheRen, cacheWen, cacheMemWen;
wire [(`DBLOCK_SIZE-1):0] cacheBytesAccess;
wire [(`DBLOCK_SIZE_BITS-1):0] cacheDin;
wire memRen, memWen;
wire [(`DBLOCK_SIZE_BITS-1):0] memDin;

 //pipeline          
wire dcache_stall, icache_stall, dcache_ren, dcache_wen;
wire [`DBLOCK_SIZE_BITS-1:0] dcache_output;
wire [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] dcache_addr;
wire [`DBLOCK_SIZE-1:0] byteSelectVector;
wire [`DBLOCK_SIZE_BITS-1:0] dcache_input;

// dcache
wire DcacheRen, DcacheWen, DcacheMemWen;
wire [`DBLOCK_SIZE-1:0] DcacheBytesAccess;
wire [`DMEM_BLOCK_ADDR_SIZE-1:0] DcacheBlockAddr;
wire [`DBLOCK_SIZE_BITS-1:0] DcacheDin;
wire DcacheHit, DcacheDirtyBit;
wire [`DBLOCK_SIZE_BITS-1:0] DcacheDout;

// icache
wire IcacheRen, IcacheMemWen;
wire [`IMEM_BLOCK_ADDR_SIZE-1:0] IcacheBlockAddr;
wire [`IBLOCK_SIZE_BITS-1:0] IcacheDin;
wire IcacheHit, IcacheDirtyBit;
wire [`IBLOCK_SIZE_BITS-1:0] IcacheDout;

pipeline pipeline(.clock(clock), 
				  .reset(reset),

                  // inputs from cache controllers
		          .dcache_stall(DcacheStall),
                  .icache_stall(IcacheStall),
                  .dcache_output(DpipelineOutput),
                  .icache_output(IpipelineOutput),
				  
                  // outputs for cache controllers
                  .dcache_ren(DcacheRen),
				  .dcache_wen(DcacheWen),
                  .icache_ren(IcacheRen),
				  .dcache_addr(DcacheAddr),
                  .icache_addr(IcacheAddr),
				  .byteSelectVector(byteSelectVector),
                  .dcache_input(DcacheInput));

icache_controller icachecontroller2check(
                        .clock(clock),
                        .reset(reset),
                        
                        // pipeline inputs
                        .ren(IcacheRen),
                        .addr(IcacheAddr),

                        // cache inputs
                        .cacheHit(IcacheHit),
                        .cacheDout(IcacheDout),
                        
                        // memory inputs
                        .memReadReady(ImemReadReady),
                        .memDout(ImemDout),

                        // pipeline outputs
                        .stall(IcacheStall),
                        .dout(IpipelineOutput),
                        
                        //both cache and memory output
                        .BlockAddr(IblockAddr),

                        // cache outputs
                        .cacheRen(IcacheRen),
                        .cacheMemWen(IcacheMemWen),
                        .cacheDin(IcacheDin),

                        // memory outputs
                        .memRen(ImemRen));

Icache_SRAM Icache(.clk(clock), 
                   .rst(reset),
                   .ren(IcacheRen), 
                   .memWen(IcacheMemWen),
                   .blockAddr(IblockAddr), 
                   .dataIn(IcacheDin), 
                   .hit(IcacheHit),
                   .dataOut(IcacheDout));




dcache_controller Dcntr(.clock(clock),
                        .reset(reset),
                        
                        // pipeline inputs
                        .ren(DcacheRen),
                        .wen(DcacheWen),
                        .addr(DcacheAddr),
                        .byteSelectVector(byteSelectVector),
                        .din(DcacheInput),

                        // cache inputs
                        .cacheHit(DcacheHit),
                        .cacheDirtyBit(DcacheDirtyBit),
                        .cacheDout(DcacheDout),
                        
                        // memory inputs
                        .memReadReady(DmemReadReady),
                        .memWriteDone(DmemWriteDone),
                        .memDout(DmemDout),
                        
                        // pipeline outputs
                        .stall(DcacheStall),
                        .dout(DpipelineOutput),
                        
                        //both cache and memory output
                        .BlockAddr(DblockAddress),
                        
                        // cache outputs
                        .cacheRen(DcacheRen),
                        .cacheWen(DcacheWen),
                        .cacheMemWen(DcacheMemWen),
                        .cacheBytesAccess(DcacheBytesAccess),
                        .cacheDin(DcacheDin),
                        
                        // memory outputs
                        .memRen(DmemRen),
                        .memWen(DmemWen),
                        .memDin(DmemDin));

Dcache_SRAM Dcache(.clk(clock), 
                   .rst(reset),
                   .ren(DcacheRen), 
                   .wen(DcacheWen), 
                   .memWen(DcacheMemWen),
                   .bytesAccess(DcacheBytesAccess),
                   .blockAddr(DblockAddress), 
                   .dataIn(DcacheDin), 
                   .hit(DcacheHit),
                   .dirtyBit(DcacheDirtyBit),
                   .dataOut(DcacheDout));

endmodule
