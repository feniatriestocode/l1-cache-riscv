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
		          .dcache_stall(DcacheStall),
                  .icache_stall(IcacheStall),
                  .dcache_output(DpipelineOutput),
                  .icache_output(IpipelineOutput),
				  .dcache_ren(DcacheRen),
				  .dcache_wen(DcacheWen),
				  .dcache_addr(DcacheAddr),
                  .icache_addr(IcacheAddr),
				  .byteSelectVector(byteSelectVector),
				  .dcache_input(DcacheInput));

icache_controller icachecontroller2check(
                        .clock(clock),
                        .reset(reset),
                        .ren(IcacheRen),
                        .addr(IcacheAddr), 
                        .cacheHit(IcacheHit),
                        .cacheDout(IcacheDout),
                        .memReadReady(ImemReadReady),
                        .memDout(ImemDout),
                        .stall(IcacheStall),
                        .dout(IpipelineOutput),
                        .BlockAddr(IblockAddr),
                        .cacheRen(IcacheRen),
                        .cacheMemWen(IcacheMemWen),
                        .cacheDin(IcacheDin),
                        .memRen(ImemRen));


                        // caches instantiated here
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
                        .ren(DcacheRen),
                        .wen(DcacheWen),
                        .addr(DcacheAddr),
                        .byteSelectVector(byteSelectVector),
                        .din(DcacheInput),
                        .cacheHit(DcacheHit),
                        .cacheDirtyBit(DcacheDirtyBit),
                        .cacheDout(DcacheDout),
                        .memReadReady(DmemReadReady),
                        .memWriteDone(DmemWriteDone),
                        .memDout(DmemDout),
                        .stall(DcacheStall),
                        .dout(DpipelineOutput),
                        .BlockAddr(DblockAddress),
                        .cacheRen(DcacheRen),
                        .cacheWen(DcacheWen),
                        .cacheMemWen(DcacheMemWen),
                        .cacheBytesAccess(DcacheBytesAccess),
                        .cacheDin(DcacheDin),
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
