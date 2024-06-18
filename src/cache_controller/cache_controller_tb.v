

module dcache_controller_tb;
            //pipeline regs
            reg clock;
            reg reset;
            reg ren;
            reg wen;
            reg [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] addr;//[15:0]
            reg [`DWORD_SIZE-1:0] byteSelectVector; //[3:0]
            reg [`DWORD_SIZE_BITS-1:0] din; //[31:0]
                                    
            // cache regs
            reg cacheHit;
            reg cacheDirtyBit;
            reg [`DBLOCK_SIZE_BITS-1:0] cacheDout;//[127:0]
                                    
            // memory regs
            reg memReadReady;
            reg memWriteDone;
            reg [((`DBLOCK_SIZE_BITS)-1):0] memDout;//[127:0]
                                    
            // pipeline wires
            wire stall;
            wire [`DWORD_SIZE_BITS-1:0] dout;//[31:0]

            // cache wires
            wire cacheEn;
            wire cacheWen;
            wire cacheMemWen;
            wire [`DBLOCK_SIZE-1:0] cacheBytesAccess;//[15:0]
            wire [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] cacheBlockAddr;//[15:0]
            wire [`DBLOCK_SIZE_BITS-1:0] cacheDin;//[127:0]
                                    
            // memory wires
            wire memRen; 
            wire memWen;
            wire [`DMEM_BLOCK_ADDR_SIZE-1:0] memBlockAddr;//[15:0]
            wire [((`DBLOCK_SIZE_BITS)-1):0]  memDin;//[127:0]




dcache_controller controller2check(
    .clock(clock),
    .reset(reset),
    .ren(ren),
    .wen(wen),
    .addr(addr),
    .byteSelectVector(byteSelectVector),
    .din(din),
// cache inputs
    .cacheHit(cacheHit),
    .cacheDirtyBit(cacheDirtyBit),
    .cacheDout(cacheDout),
 // memory inputs
    .memReadReady(memReadReady),
    .memWriteDone(memWriteDone),
    .memDout(memDout),
// pipeline outputs
    .stall(stall),
    .dout(dout),
// cache outputs
    .cacheEn(cacheEn),
    .cacheWen(cacheWen),
    .cacheMemWen(cacheMemWen),
    .cacheBytesAccess(cacheBytesAccess),
    .cacheBlockAddr(cacheBlockAddr),
    .cacheDin(cacheDin),
// memory outputs
    .memRen(memRen),
    .memWen(memWen),
    .memBlockAddr(memBlockAddr),
    .memDin(memDin));



//clock 
   always #5 clock = ~clock;

//initial stages
    initial begin
        clock = 0;
        reset = 0;
        dirty_bit = 0;
        ren = 0;
        wen = 0;
        addr = 16'b0;
        byteSelectVector = 16'b0;
        din = 128'b0;
        cacheHit = 0;
        cacheDirtyBit = 0;
        cacheDout = 128'b0;
        memReadReady = 0;
        memWriteDone = 0;
        memDout = 128'b0;




    //reset=1 function can begin
    #10;
    reset = 1;


//------------CASE 1-> SIMPLE CACHE READ HIT------------//

    #10;
    ren = 1;
    cacheHit = 1;





        $finish;
    end

initial begin
        // Monitor outputs
        $monitor("Time=%0d, clock=%b, reset=%b, ready=%b, done=%b, dirty_bit=%b, hit=%b, ren=%b, wen=%b, stall=%b, dMemWen=%b, renMem=%b, wenMem=%b, state=%b", $time, clock, reset, ready, done, dirty_bit, hit, ren, wen, stall, dMemWen, renMem, wenMem, current_state);
    end

endmodule    
