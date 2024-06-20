//// `timescale 1ns / 1ps

//`include "cache_controller.v"

module icache_controller_tb;
            //pipeline regs
            reg clock;
            reg reset;
            reg ren;
            reg [(`IADDR_SIZE-1):0] addr;
                                    
            // cache regs 
            reg cacheHit;
            reg [(`IBLOCK_SIZE_BITS-1):0] cacheDout;
                                    
            // memory regs
            reg memReadReady;
            reg [((`IBLOCK_SIZE_BITS)-1):0] memDout;
                                    
            // pipeline wires
            wire stall;
            wire [(`IWORD_SIZE_BITS-1):0] dout;

           //both cache and memory wire 
            wire [(`IMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr;

            // cache wires
            wire cacheRen;
            wire cacheMemWen;
            wire [(`IBLOCK_SIZE_BITS-1):0] cacheDin;//[127:0]
                                    
            // memory wires
            wire memRen; 


            integer test;



 
icache_controller icachecontroller2check(
    .clock(clock),
    .reset(reset),
    .ren(ren),
    .addr(addr),

    // cache inputs
    .cacheHit(cacheHit),
    .cacheDout(cacheDout),
    
    // memory inputs
    .memReadReady(memReadReady),
    .memDout(memDout),

    // pipeline outputs
    .stall(stall),
    .dout(dout),

    //both cache and memory output
    .BlockAddr(BlockAddr),

    // cache outputs
    .cacheRen(cacheRen),
    .cacheMemWen(cacheMemWen),
    .cacheDin(cacheDin),
    
    // memory outputs
    .memRen(memRen));







//clock 
   always #5 clock = ~clock;

//initial stages
    initial begin
        test = 10; //////////////////////////////////////////////////////////////////////////
        clock = 0;
        reset = 0;
        ren = 0;
        addr = {`IADDR_SIZE{1'b0}};
        cacheHit = 0;
        cacheDout = {`IBLOCK_SIZE_BITS{1'b0}};
        memReadReady = 0;
        memDout = {`IBLOCK_SIZE_BITS{1'b0}};




//reset=1 function can begin
    #10;
    reset = 1;

    #1; //delay 




//------------CASE 1-> CACHE READ MISS no writeback------------//
    test = 11; //////////////////////////////////////////////////////////////////////////
    ren = 1;
    addr = 8'b00_00_11_10; //hex 
    cacheHit = 0;
    #100;
    memReadReady = 1;
    cacheDout = {4'b1111,{`IBLOCK_SIZE_BITS-4{1'b0}}};
    memDout = {8'b10101010,{`IBLOCK_SIZE_BITS-8{1'b0}}};
    #100;
    ren = 0;
    memReadReady = 0;
    memDout = {`IBLOCK_SIZE_BITS{1'b0}};
    addr = {`IMEM_SIZE{1'b0}};


    test = 12; //////////////////////////////////////////////////////////////////////////
    #10;
    ren = 1;
    addr = 8'b11_11_11_00; //hex 0xF0 
    cacheHit = 0;
    #110;
    memReadReady = 1;
    cacheDout = {4'b0000,{`IBLOCK_SIZE_BITS-4{1'b1}}};
    memDout = {`IBLOCK_SIZE_BITS{1'b1}};
    #80;
    ren = 0;
    memReadReady = 0;
    memDout = {`IBLOCK_SIZE_BITS{1'b0}};
    addr = {`IMEM_SIZE{1'b0}};


//initialization
    test = 20; //////////////////////////////////////////////////////////////////////////
    #10;
    ren = 0;
    addr = {`IMEM_SIZE{1'b0}};
    cacheHit = 0;
    cacheDout = {`IBLOCK_SIZE_BITS{1'b0}};
    memReadReady = 0;
    memDout = {`IBLOCK_SIZE_BITS{1'b0}};


//------------CASE 2-> READ HIT ------------//
// access and hit set 1 
test = 21; //////////////////////////////////////////////////////////////////////////
#10;
ren = 1;
addr =  8'b00_01_00_00; //hex 0x10 
#2;
cacheHit = 1;
cacheDout = {`IBLOCK_SIZE_BITS{1'b1}};
#200;
ren = 0;
cacheHit = 0;
addr = {`IADDR_SIZE{1'b0}};
cacheDout = {`IBLOCK_SIZE_BITS{1'b0}};    

// access and hit set 10 
test = 22; //////////////////////////////////////////////////////////////////////////
#7;
ren = 1;
addr = 8'b10_10_11_00; //hex 0xA0 
#2;
cacheHit = 1;
cacheDout = {4'b1111,{`IBLOCK_SIZE_BITS-4{1'b0}}};
#200;
ren = 0;
cacheHit = 0;
addr = {`IADDR_SIZE{1'b0}};
cacheDout = {`IBLOCK_SIZE_BITS{1'b0}};  


        $finish;
    end

endmodule