//`include "constants.v"
//`include "config.vh"

module cpu(input clock, 
		       input reset,
		       // imem
		       output imem_ren,
           output [(`IMEM_BLOCK_ADDR_SIZE-1):0] imem_block_address,
           input [(`IBLOCK_SIZE_BITS-1):0] imem_dout,
           input imem_read_ready,
           // dmem
           output dmem_ren, 
           output dmem_wen,
           output [(`IMEM_BLOCK_ADDR_SIZE-1):0] dmem_block_address, 
           output [(`IBLOCK_SIZE_BITS-1):0] dmem_din,
           input dmem_read_ready, 
           input dmem_write_done,
           input [(`IBLOCK_SIZE_BITS-1):0] dmem_dout);     
           
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
		              .dcache_stall(dcache_stall),
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
                   .ren(IcacheRen), 
                   .memWen(IcacheMemWen),
                   .blockAddr(IcacheBlockAddr), 
                   .dataIn(IcacheDin), 
                   .hit(IcacheHit),
                   .dataOut(IcacheDout));

Dcache_SRAM Dcache(.clk(clock), 
                   .rst(reset),
                   .ren(DcacheRen), 
                   .wen(DcacheWen), 
                   .memWen(DcacheMemWen),
                   .bytesAccess(DcacheBytesAccess),
                   .blockAddr(DcacheBlockAddr), 
                   .dataIn(DcacheDin), 
                   .hit(DcacheHit),
                   .dirtyBit(DcacheDirtyBit),
                   .dataOut(DcacheDout));

dcache_controller Dcntr(.clock(clock),
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
                        .memDin(memDin));
endmodule
