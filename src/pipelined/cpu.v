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
           
           
 //pipeline          
wire dcache_stall, dcache_ren, dcache_wen;
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

D_SRAM Dcache(.clk(clock), 
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

D_CNTRL dcache_controller(// pipeline inputs
                        .clock(clock),
                        .reset(reset),
                        .ren(dcache_ren), 
                        .wen(dcache_wen),
                        .addr(dcache_addr),
                        .byteSelectVector(byteSelectVector),
                        .din(dcache_input),
                        
                        // cache inputs
                        .cacheHit(DcacheHit),
                        .cacheDirtyBit(DcacheDirtyBit),
                        .cacheDout(DcacheDout),
                        
                        // memory inputs
                        .memReadReady(dmem_ready), 
                        .memWriteDone(dmem_done),
                        .memDout(dmem_dout),
                        
                        // pipeline outputs
                        .stall(dcache_stall),
                        .dout(dcache_output),

                        // cache outputs
                        .cacheEn(DcacheEn),
                        .cacheWen(DcacheWen),
                        .cacheMemWen(DcacheMemWen),
                        .cacheBytesAccess(DcacheBytesAccess),
                        .cacheBlockAddr(DcacheBlockAddr),
                        .cacheDin(DcacheDin),
                        
                        // memory outputs
                        .memRen(dmem_ren), 
                        .memWen(dmem_wen),
                        .memBlockAddr(dmem_block_address),
                        .memDin(dmem_din)); 
endmodule
