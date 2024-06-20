//`timescale 1ns / 1ps

//`include "cache_controller.v"

module dcache_controller_tb;
            //pipeline regs
            reg clock;
            reg reset;
            reg ren;
            reg wen;
            reg [(`DADDR_SIZE-1):0] addr;//[19:0]
            reg [(`DWORD_SIZE-1):0] byteSelectVector; //[3:0]
            reg [(`DWORD_SIZE_BITS-1):0] din; //[31:0]
                                    
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


           //both cache and memory wire 
            wire [(`DMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr;

            // cache wires
            wire cacheRen;
            wire cacheWen;
            wire cacheMemWen;
            wire [(`DBLOCK_SIZE-1):0] cacheBytesAccess;//[15:0]
            wire [(`DBLOCK_SIZE_BITS-1):0] cacheDin;//[127:0]
                                    
            // memory wires
            wire memRen; 
            wire memWen;
            wire [(`DBLOCK_SIZE_BITS-1):0]  memDin;//[127:0]

            integer test;

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
    .cacheRen(cacheRen),
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
        test = 10; //////////////////////////////////////////////////////////////////////////
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
    test = 11; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1;
    addr = 8'00_01_00_00; //hex 0x10 
    din = {`DWORD_SIZE_BITS{1'b0}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    din = {`DWORD_SIZE_BITS{1'b0}};

    test = 12; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1;
    addr = 8'b10_01_00_00; //hex 0x90 
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b0}}};
    #120;
    memReadReady = 1;
    #120;
    memReadReady = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    din = {`DWORD_SIZE_BITS{1'b0}};



//set 10: same set index 01010, different tags
    test = 13; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1;
    addr = 8'b10_10_00_00; //hex 0xA0 
    din = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    din = {`DWORD_SIZE_BITS{1'b0}};


    test = 14; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1; 
    addr = 8'b01_10_00_00; //hex 0x60 
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b1}}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;
    addr = {`DADDR_SIZE{1'b0}};
    din = {`DWORD_SIZE_BITS{1'b0}};

//initialization
    test = 20; //////////////////////////////////////////////////////////////////////////
    #10;
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
test = 21; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
addr =  8'00_01_00_00; //hex 0x10 
#2;
cacheHit = 1;
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
#8;
ren = 0;
cacheHit = 0;
addr = {`DADDR_SIZE{1'b0}};
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};    

// access and hit set 10 
test = 22; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
addr = 8'b10_10_00_00; //hex 0xA0 
#2;
cacheHit = 1;
cacheDout = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
#8;
ren = 0;
cacheHit = 0;
addr = {`DADDR_SIZE{1'b0}};
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};  

//initialization
    test = 30; //////////////////////////////////////////////////////////////////////////
    #10;
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
test = 31; //////////////////////////////////////////////////////////////////////////
#10;
wen = 1;
addr = 8'00_01_00_00; //hex 0x10 
din = {`DWORD_SIZE_BITS{1'b1}};
#2;
cacheHit = 1;
#90;
wen = 0;
addr = {`DMEM_SIZE{1'b0}};
din = {`DWORD_SIZE_BITS{1'b0}};
cacheHit = 0;

test = 32; //////////////////////////////////////////////////////////////////////////
#10;
wen = 1;
addr = 8'b10_10_00_00; //hex 0xA0 
din = {`DWORD_SIZE_BITS{1'b0}};
#2;
cacheHit = 1;
#90;
wen = 0;
addr = {`DMEM_SIZE{1'b0}};
din = {`DWORD_SIZE_BITS{1'b0}};
cacheHit = 0;


//initialization
    test = 40; //////////////////////////////////////////////////////////////////////////
    #10;
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

//------------CASE 4-> CACHE READ MISS no writeback------------//
    test = 41; //////////////////////////////////////////////////////////////////////////
    ren = 1;
    addr = 8'b00_00_01_10; //hex 0x06 
    cacheHit = 0;
    cacheDirtyBit = 0;
    #100;
    memReadReady = 1;
    memDout = {8'b10101010,{`DBLOCK_SIZE_BITS-8{1'b0}}};
    #100;
    ren = 0;
    memReadReady = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};
    addr = {`DMEM_SIZE{1'b0}};


    test = 42; //////////////////////////////////////////////////////////////////////////
    #10;
    ren = 1;
    addr = 8'b11_11_00_00; //hex 0xF0 
    cacheHit = 0;
    cacheDirtyBit = 0;
    #110;
    memReadReady = 1;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};
    #80;
    ren = 0;
    memReadReady = 0;
    memDout = {`DBLOCK_SIZE_BITS{1'b0}};
    addr = {`DMEM_SIZE{1'b0}};






//initialization
    test = 50; //////////////////////////////////////////////////////////////////////////
    #10;
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


//------------CASE 5-> CACHE READ MISS with writeback------------//
//read miss in set 16  
test = 51; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
addr = 8'b00_11_00_00; //hex 0x30 
#2;
cacheHit = 0;
cacheDirtyBit = 1;
#18;
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
addr = {`DMEM_SIZE{1'b0}};
memDout = {`DBLOCK_SIZE_BITS{1'b0}};


//read miss in set 29
test = 52; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
addr = 8'b11_01_00_00; //hex 0xD0 
#2;
cacheHit = 0;
cacheDirtyBit = 1;
#18;
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
addr = {`DMEM_SIZE{1'b0}};
memDout = {`DBLOCK_SIZE_BITS{1'b0}};





//initialization
    test = 60; //////////////////////////////////////////////////////////////////////////
    #10;
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


//------------CASE 6-> CACHE WRITE MISS with writeback------------//
test = 61; //////////////////////////////////////////////////////////////////////////
#10;
wen = 1;
addr = 8'b11_11_00_00; //hex  0xF0 
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
addr = {`DMEM_SIZE{1'b0}};
din = {`DWORD_SIZE_BITS{1'b0}};

test = 62; //////////////////////////////////////////////////////////////////////////
#10;
wen = 1;
addr = 8'b00_10_00_00; //hex 0x20 
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
addr = {`DMEM_SIZE{1'b0}};
din = {`DWORD_SIZE_BITS{1'b0}};


//initialization
    test = 70; //////////////////////////////////////////////////////////////////////////
    #10;
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
    test = 71; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1;
    addr = 8'b01_01_00_00; //hex 0x50 
    byteSelectVector = 4'b0001;
    din = {`DWORD_SIZE_BITS{1'b0}};
    #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;

    test = 72; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1;
    addr = 8'b00_01_00_00; //hex 0x10 
    byteSelectVector = 4'b1000;
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b0}}};
    byteSelectVector = 4'b0001;
    #120;
    memReadReady = 1;
    #120;
    memReadReady = 0;
    wen = 0;

//set 10: same set index 01010, different tags
    test = 73; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1;
    addr = 8'b11_10_00_00; //hex 0xE0 
    byteSelectVector = 4'b1100;
    din = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;

    test = 74; //////////////////////////////////////////////////////////////////////////
    #10;
    wen = 1; 
    addr = 8'b10_10_00_00; //hex 0xA0 
    byteSelectVector = 4'b0100;
    din = {4'b1010,{`DWORD_SIZE_BITS-4{1'b1}}};
     #90;
    memReadReady = 1;
    #100;
    memReadReady = 0;
    wen = 0;


//initialization
    test = 80; //////////////////////////////////////////////////////////////////////////
    #10;
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
test = 81; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
#2;
cacheHit = 1;
addr = 8'b00_11_00_00; //hex 0x30 
byteSelectVector = 4'b0100;
cacheDout = {`DBLOCK_SIZE_BITS{1'b0}};
#8;
ren = 0;
cacheHit = 0;


// access and hit set 10 
test = 82; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
#2;
cacheHit = 1;
addr = 8'b10_11_00_00; ///hex 0xB0 
byteSelectVector = 4'b0010;
cacheDout = {4'b1111,{`DWORD_SIZE_BITS-4{1'b0}}};
#8;
ren = 0;
cacheHit = 0;


//initialization
    test = 90; //////////////////////////////////////////////////////////////////////////
    #10;
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


endmodule    
