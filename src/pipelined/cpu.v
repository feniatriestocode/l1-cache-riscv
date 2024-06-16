`include "constants.v"
`include "config.vh"

module cpu(input clock, 
		   input reset,
		   // imem
		   output imem_ren,
           output [($clog2(`MEM_SIZE)-1):0] imem_block_address,
           input [((`WORD_SIZE*`BLOCK_SIZE)-1):0] imem_dout,
           input imem_ready,
           // dmem
           output dmem_ren, 
           output dmem_wen,
           output [($clog2(`MEM_SIZE)-1):0] dmem_block_address, 
           output [((`WORD_SIZE*`BLOCK_SIZE)-1):0] dmem_din,
           input dmem_ready, 
           input dmem_done,
           input [((`WORD_SIZE*`BLOCK_SIZE)-1):0] dmem_dout);     
           
           
 //pipeline          
wire dcache_stall, dcache_ren, dcache_wen;
wire [] dcache_output;
wire [] dcache_addr;
wire [] byteSelectVector;
wire [] dcache_input;

// dcache
wire DcacheEn, DcacheWen, DcacheMemWen;
wire [] DcacheBytesAccess;
wire [] DcacheBlockAddr;
wire [] DcacheDin;
wire DcacheHit, DcacheDirtyBit;
wire [] DcacheDout;


// icache
wire IcacheEn, IcacheMemWen;
wire [] IcacheBlockAddr;
wire [] IcacheDin;
wire IcacheHit, IcacheDirtyBit;
wire [] IcacheDout;

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
// to be implemented !!!!!!!!!!!!!!!!!!!!!
Icache_SRAM( Icache(.clk(clock), 
                .rst(reset),
                .en(IcacheEn), 
                .memWen(IcacheMemWen),
                .blockAddr(IcacheBlockAddr), .
                .dataIn(IcacheDin), .
                .hit(IcacheHit),
                .dirtyBit(IcacheDirtyBit),
                .dataOut(IcacheDout));

D_SRAM Dcache(.clk(clock), 
                .rst(reset),
                .en(DcacheEn), 
                .wen(DcacheWen), 
                .dmemWen(DcacheMemWen),
                .bytesAccess(DcacheBytesAccess),
                .blockAddr(DcacheBlockAddr), .
                .dataIn(DcacheDin), .
                .hit(DcacheHit),
                .dirtyBit(DcacheDirtyBit),
                .dataOut(DcacheDout));

dcache_controller(// pipeline inputs
                        .clock(clock,
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
