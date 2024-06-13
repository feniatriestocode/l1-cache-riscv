//USEFUL SITES: 
// RISCV BYTE ADDRESSING: https://projectf.io/posts/riscv-load-store/

/**A 2-WAY ASSOCIATIVE CACHE**********/ 
/**CACHE SIZE 1KB // 1024 BYTES*******/
/**CACHE BLOCK SIZE 16 BYTES**********/
/**CACHE WORD SIZE 32bits - 4 BYTES***/

`timescale 1ns/1ps
`include "constants.vh"

module D_SRAM(clk, rst, en, wen, dmemWen, bytesAccess, blockAddr, dataIn, hit, dirtyBit, dataOut);
    //INPUT PORTS//
    input clk, rst;
    input en, wen, dmemWen;
    input [`BLOCK_BYTES_NUM-1:0] bytesAccess;
    input [`TAG_BITS+`SET_INDEX_BITS:0] blockAddr;
    input [`BLOCK_SIZE_BITS-1:0] dataIn;
    //OUTPUT PORTS//
    output wire hit;
    output wire dirtyBit;
    output wire [`BLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM
    reg [`ASSOCIATIVITY-1:0]   valid_col  [`BLOCK_NUM-1:0];
    reg [`ASSOCIATIVITY-1:0]   dirty_col  [`BLOCK_NUM-1:0];
    reg [`ASSOCIATIVITY-1:0]   status_col [`BLOCK_NUM-1:0]; 
    reg [`TAG_BITS-1:0]        tag_col    [`BLOCK_NUM-1:0][`ASSOCIATIVITY-1:0];
    reg [`BLOCK_SIZE_BITS-1:0] data_col   [`BLOCK_NUM-1:0][`ASSOCIATIVITY-1:0];

    //ADDRESS' SEGS
    wire [`BLOCK_OFFSET_BITS-1:0] offset;
    wire [`SET_INDEX_BITS-1:0] index;
    wire [`TAG_BITS-1:0] tag;
    
    //BLOCK ADDRESS = [TAG][INDEX]
    assign index = addr[`SET_INDEX_BITS-1:0];
    assign tag   = addr[`TAG_BITS+`SET_INDEX_BITS-1:`SET_INDEX_BITS]; 

    //******************************ASYCHRONOUS HIT*********************************//
    integer j;
    reg [`ASSOCIATIVITY-1:0] hit_reg;

    always @(addr or en or rst)begin
        for(j=0; j<`ASSOCIATIVITY; j++)begin
            if(en && rst)
                hit_reg[j] = (tag_col[index][j] == tag) && valid_col[index][j];
            else
                hit_reg[j] = {`ASSOCIATIVITY{1'b0}};
        end
    end

    assign hit = |hit_reg;

    //****************************SYNCHRONOUS READ DATA****************************//

    integer i;
    reg [`BLOCK_SIZE_BITS-1:0] dataOut_reg;

    always @(hit or en or rst)begin
        dataOut_reg = {`BLOCK_SIZE_BITS{1'b0}};

        for(i=0; i<`ASSOCIATIVITY; i=i+1)
            if(en && rst && hit_reg[i] == 1'b1)begin
                dataOut_reg = data_col[index][i];
            end
    end

    assign dataOut = dataOut_reg;

    //***************************SYNCHRONOUS WRITE DATA***************************//
    integer m,k,l;
    reg dirtyBit_reg;
    reg found;

    always @(posedge clk or negedge rst)begin
        if(!rst)begin
            dirtyBit_reg <= 1'b0;
        end
        else begin
            if(wen && hit)
                for(m=0; m<`ASSOCIATIVITY; m=m+1)begin
                    if(hit_reg[m])begin
                        valid_col [index][m]  <= 1'b1;
                        dirty_col [index][m]  <= 1'b1;
                        status_col[index][m]  <= 1'b1;
                        tag_col   [index][m]  <= tag;

                        //PLRU POLICY
                        if(&status_col)begin
                            for(k=0; k<`ASSOCIATIVITY; k=k+1)
                                if(k != m)
                                    status_col[index][k] <= 1'b0;
                        end
                        
                        //CACHE WRITE BASED ON WHICH BYTE WE WANT TO ACCESS
                        for(l=0; l<`BLOCK_BYTES_NUM; l=l+1)begin
                            if(bytesAccess[l])
                                data_col[index][m][(l*8)+:8] = dataIn[(l*8)+:8];
                        end

                    end
                end
            else if(wen && !hit)begin
                found <= 0;
                for(m=0; m<`ASSOCIATIVITY; m=m+1)
                    if(!status_col[index][m] && !found)begin
                        dirtyBit_reg <= dirty_col[index][m];
                        found = 1'b1;
                    end

                    if(dmemWen)begin
                        dirty_col[index][m] <= 1'b0;
                        valid_col[index][m] <= 1'b1;
                        status_col[index][m] <= 1'b1;
                        tag_col[index][m] <= tag;
                        data_col[index][m] <= dataIn;

                        if(&status_col)begin
                            for(k=0; k<`ASSOCIATIVITY; k=k+1)
                                if(k != m)
                                    status_col[index][k] <= 1'b0;
                        end
                    end
            end
        end
    end

    assign dirtyBit = dirtyBit_reg;

endmodule