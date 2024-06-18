

module dcache_controller_tb;
            //pipeline regs
            reg clock;
            reg reset;
            reg ren;
            reg wen;
            reg [`DMEM_SIZE-1:0] addr;//[15:0]
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


           //both cache and memory wire 
            wire [(`DMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr,

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
        ren = 0;
        wen = 0;
        addr = {`DTAG_SIZE+`DSET_INDEX_SIZE{1'b0}};
        byteSelectVector = {`DWORD_SIZE{1'b1}};
        din = {`DWORD_SIZE_BITS{1'b0}};
        cacheHit = 0;
        cacheDirtyBit = 0;
        cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
        memReadReady = 0;
        memWriteDone = 0;
        memDout = {`DBLOCK_SIZE_BITS{1'b0}};




    //reset=1 function can begin
    #10;
    reset = 1;


//------------CASE 1-> 4 CACHE WRITE MISSES ------------//
//set 0:
    #10;
    wen = 1;
    addr = {{`DTAG_SIZE{1'b0}},{`DSET_INDEX_SIZE{1'b0}}};
    din = {`DWORD_SIZE_BITS{1'b1}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;


    #10;
    addr = {{`DTAG_SIZE{1'b1}},{`DSET_INDEX_SIZE{1'b0}}};
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b0}}};
    byteSelectVector = 
    #120;
    memReadReady = 1;
    #120;
    memReadReady = 0;
    wen = 0;

//set 2:
    #10;
    addr = {{`DTAG_SIZE{1'b0}},{5'b0010}};
    din = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;

    #10;
    addr = {{`DTAG_SIZE{1'b1}},{5'b0010}};
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b1}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
//initialization
    ren = 0;
    wen = 0;
    addr = {`DTAG_SIZE+`DSET_INDEX_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};

//------------CASE 2-> READ HIT ------------//
#10;
ren = 1;
cacheHit = 1;
addr = {{`DTAG_SIZE{1'b0}},{5'b0010}};
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};

#10;
ren = 0;
cacheHit = 0;

#10;
ren = 1;
cacheHit = 1;
addr = {{`DTAG_SIZE{1'b1}},{5'b0010}};
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};


//initialization
    ren = 0;
    wen = 0;
    addr = {`DTAG_SIZE+`DSET_INDEX_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};

//------------CASE 3-> CACHE WRITE HIT ------------//
#10;
wen = 1;
cacheHit = 1;
addr = {{`DTAG_SIZE{1'b0}},{`DSET_INDEX_SIZE{1'b0}}};
din = {`DWORD_SIZE_BITS{1'b0}};
#90;
memReadReady = 1;
#100;
memReadReady = 0;
wen = 0;


#10;
wen = 1;
cacheHit = 1;
addr = {{`DTAG_SIZE{1'b0}},{`DSET_INDEX_SIZE{1'b0}}};
din = {`DWORD_SIZE_BITS{1'b0}};
#90;
memReadReady = 1;
#100;
memReadReady = 0;

//initialization
    ren = 0;
    wen = 0;
    addr = {`DTAG_SIZE+`DSET_INDEX_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};

//------------CASE 4-> CACHE READ MISS no writeback------------//






//initialization
    ren = 0;
    wen = 0;
    addr = {`DTAG_SIZE+`DSET_INDEX_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};


//------------CASE 5-> CACHE READ MISS with writeback------------//
cacheDirtyBit = 1;






//initialization
    ren = 0;
    wen = 0;
    addr = {`DTAG_SIZE+`DSET_INDEX_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};


//------------CASE 6-> CACHE WRITE MISS with writeback------------//
cacheDirtyBit = 1;

        $finish;
    end

initial begin
        // Monitor outputs
        $monitor("Time=%0d, clock=%b, reset=%b, ready=%b, done=%b, dirty_bit=%b, hit=%b, ren=%b, wen=%b, stall=%b, dMemWen=%b, renMem=%b, wenMem=%b, state=%b", $time, clock, reset, ready, done, dirty_bit, hit, ren, wen, stall, dMemWen, renMem, wenMem, current_state);
    end

endmodule    
