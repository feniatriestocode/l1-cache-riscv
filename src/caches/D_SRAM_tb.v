`timescale 1ns/1ps

module D_SRAM_tb;
    //INPUT PORTS//
    reg clk, rst;
    reg en, wen, dmemWen;
    reg [`BLOCK_BYTES_NUM-1:0] bytesAccess;
    reg [`ADDR_SIZE-1:0] addr;
    reg [`BLOCK_SIZE_BITS-1:0] dataIn;
    //OUTPUT PORTS//
    wire hit;
    wire dirtyBit;
    wire [`BLOCK_SIZE_BITS-1:0] dataOut;

    D_SRAM D_SRAM_inst(clk, rst, en, wen, dmemWen, bytesAccess, addr, dataIn, hit, dirtyBit, dataOut);
    
    initial begin 
        clk=0;
        rst=0;
        #20 rst=1;
        #10 adrr=0;
            wen=0;
            en=0;
            


    end
    
    always begin
        #5 clk = ~clk;
    end

    initial begin
        #60000 $finish;
    end
    
endmodule