`timescale 1ns/1ps

`include "constants.vh"

module Dcache_SRAM_tb;
    reg clk, rst;
    reg ren, wen, memWen;
    reg [`DBLOCK_SIZE-1:0] bytesAccess;
    reg [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] blockAddr;
    reg [`DBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire dirtyBit;
    wire [`DBLOCK_SIZE_BITS-1:0] dataOut;

    Dcache_SRAM D_SRAM_inst(.clk(clk), .rst(rst), .ren(ren), .wen(wen), .memWen(memWen), .bytesAccess(bytesAccess), 
                       .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dirtyBit(dirtyBit), .dataOut(dataOut));

    initial begin
        ren=0;
        wen=0;
        memWen=0;
        clk=0;
        rst=0;
        #20 rst=1;
        #16
        
        //-----------------------------SET 0 - TAG 000 WRITE MISS-------------------------------------// 
    
        ren=0;
        wen=1;
        memWen=0;
        blockAddr={3'b000,1'b0};
        bytesAccess={8'b11110000};
        dataIn={32'b10101010101010101010101010101010,{`DBLOCK_SIZE_BITS-32{1'b0}}};

        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //-----------------------------SET 0 - TAG 000 WRITE FROM MEM--------------------------// 
        #10

        ren=0;
        wen=0;
        memWen=1;
        blockAddr={3'b000,1'b0};
        dataIn={{32{1'b1}},{`DBLOCK_SIZE_BITS{1'b1}}};
        
        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); //

        //----------------------------SET 0 - TAG 000 WRITE HIT-------------------------------------//
        #10 

        ren=0;
        wen=1;
        memWen=0;
        blockAddr={3'b000,1'b0};
        bytesAccess={8'b11110000};
        dataIn={32'b10101010101010101010101010101010,{`DBLOCK_SIZE_BITS-32{1'b0}}};

        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //----------------------------SET 0 - TAG 001 READ MISS------------------------------------//

        #10

        ren=1;
        wen=0;
        memWen=0;
        blockAddr={3'b001,1'b0};

        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //-----------------------------SET 0 - TAG 001 WRITE FROM MEM--------------------------// 
        #10

        ren=0;
        wen=0;
        memWen=1;
        blockAddr={3'b001,1'b0};
        dataIn={{32{1'b0}},{`DBLOCK_SIZE_BITS-32{1'b1}}};
        
        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //----------------------------SET 0 - TAG 010 READ MISS------------------------------------//

        #10

        ren=1;
        wen=0;
        memWen=0;
        blockAddr={3'b010,1'b0};

        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //-----------------------------SET 0 - TAG 010 WRITE FROM MEM--------------------------// 
        #10

        ren=0;
        wen=0;
        memWen=1;
        blockAddr={3'b010,1'b0};
        dataIn={{48{1'b1}},{`DBLOCK_SIZE_BITS-48{1'b0}}};
        
        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //----------------------------SET 0 - TAG 100 READ MISS------------------------------------//

        #10

        ren=1;
        wen=0;
        memWen=0;
        blockAddr={3'b100,1'b0};

        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //-----------------------------SET 0 - TAG 100 WRITE FROM MEM--------------------------// 
        #10

        ren=0;
        wen=0;
        memWen=1;
        blockAddr={3'b100,1'b0};
        dataIn={{48{1'b0}},{`DBLOCK_SIZE_BITS-48{1'b1}}};
        
        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //-----------------------------SET 0 - TAG 111 READ MISS -----------------------------// 
        #10

        ren=1;
        wen=0;
        memWen=0;
        blockAddr={3'b111,1'b0};
        
        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 

        //-----------------------------SET 0 - TAG 100 WRITE FROM MEM--------------------------// 
        #10

        ren=0;
        wen=0;
        memWen=1;
        blockAddr={3'b111,1'b0};
        dataIn={{30{1'b0}},{`DBLOCK_SIZE_BITS-30{1'b1}}};
        
        $display("HIT: %d || DIRTYBIT: %d || DATAOUT: %d",hit,dirtyBit,dataOut); 



        

    end

    always #5 clk = ~clk;
   

      
endmodule