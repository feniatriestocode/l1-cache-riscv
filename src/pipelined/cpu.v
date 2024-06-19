`include "constants.v"
`include "config.vh"

module cpu(input clock, 
		   input reset,
		   // imem
		   output imem_ren,
           output [($clog2(`IMEM_SIZE)-1):0] imem_block_address,
           input [((`IWORD_SIZE*`IBLOCK_SIZE)-1):0] imem_dout,
           input imem_ready,
           // dmem
           output dmem_ren, 
           output dmem_wen,
           output [($clog2(`DMEM_SIZE)-1):0] dmem_block_address, 
           output [((`DWORD_SIZE*`DBLOCK_SIZE)-1):0] dmem_din,
           input dmem_ready, 
           input dmem_done,
           input [((`DWORD_SIZE*`DBLOCK_SIZE)-1):0] dmem_dout);     
           
//dcache_controller 
reg ren, wen;
reg [(`DADDR_SIZE-1):0] addr;
reg [(`DWORD_SIZE-1):0] byteSelectVector;
reg [(`DWORD_SIZE_BITS-1):0] din;
reg cacheHit;
reg cacheDirtyBit;
reg [(`DBLOCK_SIZE_BITS-1):0] cacheDout;
reg memReadReady, memWriteDone;
reg [(`DBLOCK_SIZE_BITS-1):0] memDout;

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
wire DcacheEn, DcacheWen, DcacheMemWen;
wire [`DBLOCK_SIZE-1:0] DcacheBytesAccess;
wire [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] DcacheBlockAddr;
wire [`DBLOCK_SIZE_BITS-1:0] DcacheDin;
wire DcacheHit, DcacheDirtyBit;
wire [`DBLOCK_SIZE_BITS-1:0] DcacheDout;

// icache
wire IcacheEn, IcacheMemWen;
wire [`ITAG_SIZE+`ISET_INDEX_SIZE-1:0] IcacheBlockAddr;
wire [`IBLOCK_SIZE_BITS-1:0] IcacheDin;
wire IcacheHit, IcacheDirtyBit;
wire [`IBLOCK_SIZE_BITS-1:0] IcacheDout;

pipeline pipeline(.clock(clock), 
				  .reset(reset),
		/*input*/ .dcache_stall(dcache_stall),
                  .icache_stall(icache_stall),
                  .dcache_output(dcache_output),
				  .dcache_ren(dcache_ren),
				  .dcache_wen(dcache_wen),
				  .dcache_addr(dcache_addr),
				  .byteSelectVector(byteSelectVector),
				  .dcache_input(dcache_input));

// caches instantiated here
Icache_SRAM Icache(.clk(clock), 
                .rst(reset),
                .en(IcacheEn), 
                .memWen(IcacheMemWen),
                .blockAddr(IcacheBlockAddr), 
                .dataIn(IcacheDin), 
                .hit(IcacheHit),
                .dirtyBit(IcacheDirtyBit),
                .dataOut(IcacheDout));

Dcache_SRAM Dcache(.clk(clock), 
                .rst(reset),
                .en(DcacheEn), 
                .wen(DcacheWen), 
                .dmemWen(DcacheMemWen),
                .bytesAccess(DcacheBytesAccess),
                .blockAddr(DcacheBlockAddr), 
                .dataIn(DcacheDin), 
                .hit(DcacheHit),
                .dirtyBit(DcacheDirtyBit),
                .dataOut(DcacheDout));

dcache_controller Dcntr(
  // Instantiate dcache_controller
    .clock(clock),
    .reset(reset),
    .ren(ren),
    .wen(wen),
    .addr(addr),
    .byteSelectVector(byteSelectVector),
    .din(din),
    .cacheHit(cacheHit),
    .cacheDirtyBit(cacheDirtyBit),
    .cacheDout(cacheDout),
    .memReadReady(memReadReady),
    .memWriteDone(memWriteDone),
    .memDout(memDout),
    .stall(stall),
    .dout(dout),
    .BlockAddr(BlockAddr),
    .cacheRen(cacheRen),
    .cacheWen(cacheWen),
    .cacheMemWen(cacheMemWen),
    .cacheBytesAccess(cacheBytesAccess),
    .cacheDin(cacheDin),
    .memRen(memRen),
    .memWen(memWen),
    .memDin(memDin)
);

endmodule
