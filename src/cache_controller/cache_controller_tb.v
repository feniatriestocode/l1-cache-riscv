

module dcache_controller_tb;
            //pipeline regs
            reg clock;
            reg reset;
            reg ren;
            reg wen;
<<<<<<< Updated upstream
            reg [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] addr;//[15:0]
            reg [`DWORD_SIZE-1:0] byteSelectVector; //[3:0]
            reg [`DWORD_SIZE_BITS-1:0] din; //[31:0]
=======
            reg [(`DADDR_SIZE-1):0] addr;//[19:0]
            reg [(`DWORD_SIZE-1):0] byteSelectVector; //[3:0]
            reg [(`DWORD_SIZE_BITS-1):0] din; //[31:0]
>>>>>>> Stashed changes
                                    
            // cache regs
            reg cacheHit;
            reg cacheDirtyBit;
            reg [(`DBLOCK_SIZE_BITS-1):0] cacheDout;//[127:0]
                                    
            // memory regs
            reg memReadReady;
            reg memWriteDone;
            reg [((`DBLOCK_SIZE_BITS)-1):0] memDout;//[127:0]
                                    
            // pipeline wires
            wire stall;
            wire [(`DWORD_SIZE_BITS-1):0] dout;//[31:0]

            // cache wires
            wire cacheEn;
            wire cacheWen;
            wire cacheMemWen;
            wire [(`DBLOCK_SIZE-1):0] cacheBytesAccess;//[15:0]
            wire [(`DBLOCK_SIZE_BITS-1):0] cacheDin;//[127:0]
                                    
            // memory wires
            wire memRen; 
            wire memWen;
<<<<<<< Updated upstream
            wire [`DMEM_BLOCK_ADDR_SIZE-1:0] memBlockAddr;//[15:0]
            wire [((`DBLOCK_SIZE_BITS)-1):0]  memDin;//[127:0]
=======
            wire [(`DBLOCK_SIZE_BITS-1):0]  memDin;//[127:0]
>>>>>>> Stashed changes




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
//both memory and cache 
    .BlockAddr(BlockAddr),
// cache outputs
    .cacheEn(cacheEn),
    .cacheWen(cacheWen),
    .cacheMemWen(cacheMemWen),
    .cacheBytesAccess(cacheBytesAccess),
    .cacheDin(cacheDin),
// memory outputs
    .memRen(memRen),
    .memWen(memWen),
    .memDin(memDin));



//clock 
   always #5 clock = ~clock;

//initial stages
    initial begin
        clock = 0;
        reset = 0;
        ren = 0;
        wen = 0;
        addr = {`DADDR_SIZE{1'b0}};
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
//set 1: same set index 00001, different tags 
    #10;
    wen = 1;
    addr = 20'b0000 0000 0100 0001 0000; //hex 0x410
    din = {`DWORD_SIZE_BITS{1'b0}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    

<<<<<<< Updated upstream
    addr = {{`DTAG_SIZE{1'b1}},{`DSET_INDEX_SIZE{1'b0}}};
=======

    #10;
    wen = 1;
    addr = 20'b0000 0000 0100 0001 0000; //hex 0x20010 
>>>>>>> Stashed changes
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b0}}};
    byteSelectVector = 
    #120;
    memReadReady = 1;
    #120;
    memReadReady = 0;

<<<<<<< Updated upstream
//set 2:
    addr = {{`DTAG_SIZE{1'b0}},{5'b0010}};
=======
//set 10: same set index 01010, different tags
    #10;
    wen = 1;
    addr = 20'b0000 1000 0100 1010 0000; //hex 0x084A0
>>>>>>> Stashed changes
    din = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;

<<<<<<< Updated upstream

    addr = {{`DTAG_SIZE{1'b1}},{5'b0010}};
=======
    #10;
    wen = 1; 
    addr = 20'b0010 0001 0000 1010 0000;
>>>>>>> Stashed changes
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b1}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
//initialization
    ren = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};

//------------CASE 2-> READ HIT ------------//
// access and hit set 1 
#10;
ren = 1;
#2;
cacheHit = 1;
addr = 20'b0000 0000 0100 0001 0000;
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};

#8;
ren = 0;
cacheHit = 0;
// access and hit set 10 
#10;
ren = 1;
#2;
cacheHit = 1;
addr = 20'b0000 1000 0100 1010 0000;
cacheDout = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
#8;

//initialization
    ren = 0;
    wen = 0;
    addr = {`DMEM_SIZE{1'b0}};
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
#2;
cacheHit = 1;
addr = 20'b0000 0000 0100 0001 0000;
din = {`DWORD_SIZE_BITS{1'b1}};
#90;
memReadReady = 1;
#98;
memReadReady = 0;


#10;
wen = 1;
#2;
cacheHit = 1;
addr = 20'b0000 0000 0100 0001 0000;
din = {`DWORD_SIZE_BITS{1'b0}};
#90;
memReadReady = 1;
#98;
memReadReady = 0;

<<<<<<< Updated upstream
=======
//initialization
    ren = 0;
    wen = 0;
    addr = {`DMEM_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};
>>>>>>> Stashed changes

//------------CASE 4-> CACHE READ MISS no writeback------------//
    ren = 1;
    addr = 20'b0000 0000 0010 0110 0000; //hex 0x0260
    cacheHit = 0;
    cacheDirtyBit = 0;
    #100;
    memReadReady = 1;
    memDout = {8'b10101010,{`DBLOCK_SIZE_BITS-8{1'b0}}};
    #100;
    ren = 0;
    memReadReady = 0;

    #10;
    ren = 1;
    addr = 20'b0000 1111 0010 1111 0000; //hex 0x0F2F0
    cacheHit = 0;
    cacheDirtyBit = 0;
    #110;
    memReadReady = 1;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};
    #80;
    ren = 0;
    memReadReady = 0;
    #10;






<<<<<<< Updated upstream
=======
//initialization
    ren = 0;
    wen = 0;
    addr = {`DMEM_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};

>>>>>>> Stashed changes

//------------CASE 5-> CACHE READ MISS with writeback------------//
//read miss in set 16  
#10;
ren = 1;
cacheDirtyBit = 1;
addr = 20'b0000 0000 1111 0000 0000; //hex 
cacheHit = 0;
#20;
memWriteDone = 1;
#100;
memWriteDone= 0;
#20;
memReadReady = 1;
memDout = {{8'b11111111},{`DBLOCK_SIZE_BITS-8{1'b0}}};
#100;
memReadReady = 0;
ren = 0;
cacheDirtyBit = 0;


//read miss in set 29
#10;
ren = 1;
cacheDirtyBit = 1;
cacheHit = 0;
addr = 20'b0000 1111 0001 1101 0000;
#20;
memWriteDone = 1;
#100;
memWriteDone= 0;
#20;
memReadReady = 1;
memDout = {{8'b11110000},{`DBLOCK_SIZE_BITS-8{1'b0}}};
#100;
memReadReady = 0;
ren = 0;
cacheDirtyBit = 0;






<<<<<<< Updated upstream
=======
//initialization
    ren = 0;
    wen = 0;
    addr = {`DMEM_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};

>>>>>>> Stashed changes

//------------CASE 6-> CACHE WRITE MISS with writeback------------//
//cache write in set 15
#10;
wen = 1;
addr = 20'b1111 0000 1100 1111 0000; //hex 0xF0CF0 
din = {4'b0010,{`DWORD_SIZE_BITS-4{1'b0}}};
cacheHit = 0;
cacheDirtyBit = 1;
#20;
memWriteDone = 1;
#100;
memWriteDone= 0;
#20;
memReadReady = 1;
#100;
memReadReady = 0;
wen = 0;
cacheDirtyBit = 0;

//cache write in set 18
#10;
wen = 1;
addr = 20'b0000 1111 0001 0010 0000; //hex 0x0F120 
din = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
cacheHit = 0;
cacheDirtyBit = 1;
#20;
memWriteDone = 1;
#100;
memWriteDone= 0;
#20;
memReadReady = 1;
#100;
memReadReady = 0;
wen = 0;
cacheDirtyBit = 0;
//initialization
    ren = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};


//------------CASE 7-> 4 CACHE WRITE MISSES with different byteSelectVector ------------//
//set 9: same set index 9, different tags 
    #10;
    wen = 1;
    addr = 20'b0000 0000 0100 1001 0000; //hex 0x0490 
    byteSelectVector = 4'b0001;
    din = {`DWORD_SIZE_BITS{1'b0}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;


    #10;
    wen = 1;
    addr = 20'b0000 0000 0100 1001 0000; //hex 0x20010 
    byteSelectVector = 4'b1000;
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b0}}};
    byteSelectVector = 
    #120;
    memReadReady = 1;
    #120;
    memReadReady = 0;
    wen = 0;

//set 10: same set index 01010, different tags
    #10;
    wen = 1;
    addr = 20'b0000 1000 0100 1010 0000; //hex 0x084A0
    byteSelectVector = 4'b1100;
    din = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;

    #10;
    wen = 1; 
    addr = 20'b0010 0001 0000 1010 0000;
    byteSelectVector = 4'b0100;
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b1}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
//initialization
    ren = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};


//------------CASE 8-> READ HIT with different byteSelectVector ------------//
// access and hit set 1 
#10;
ren = 1;
#2;
cacheHit = 1;
addr = 20'b0000 0000 0100 0001 0000;
byteSelectVector = 4'b0100;
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
#8;
ren = 0;
cacheHit = 0;


// access and hit set 10 
#10;
ren = 1;
#2;
cacheHit = 1;
addr = 20'b0000 1000 0100 1010 0000;
byteSelectVector = 4'b0010;
cacheDout = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
#8;

//initialization
    ren = 0;
    wen = 0;
    addr = {`DMEM_SIZE{1'b0}};
    byteSelectVector = {`DWORD_SIZE{1'b1}};
    din = {`DWORD_SIZE_BITS{1'b0}};
    cacheHit = 0;
    cacheDirtyBit = 0;
    cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memWriteDone = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};







        $finish;
    end

initial begin
        // Monitor outputs
        $monitor("Time=%0d, clock=%b, reset=%b, ready=%b, done=%b, dirty_bit=%b, hit=%b, ren=%b, wen=%b, stall=%b, dMemWen=%b, renMem=%b, wenMem=%b, state=%b", $time, clock, reset, ready, done, dirty_bit, hit, ren, wen, stall, dMemWen, renMem, wenMem, current_state);
    end

endmodule    
