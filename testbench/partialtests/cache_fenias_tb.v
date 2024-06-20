//// `timescale 1ns / 1ps


module cache_tb;
    localparam  LINE_WIDTH = 32;
    
    reg clk;
    reg wren; 
    reg rden; 
    reg [LINE_WIDTH:0] addr;
    reg [LINE_WIDTH:0] data_in;
    wire cache_hit;
    wire [LINE_WIDTH:0] data_out;
    wire [LINE_WIDTH:0] mem_out;

    cache #( .NUM_LINES(4) , .NUM_SETS(4) , .BLOCK_SIZE(32) , .SIZE() , .LINE_WIDTH(LINE_WIDTH) , 
    .INDEX_WIDTH(2) , .OFFSET_WIDTH(1) , .TAG_WIDTH(29) ) cache_inst(clk, wren, rden, addr, data_in, cache_hit, data_out, mem_out);

    initial begin
        clk = 0;
        wren = 0;
        rden = 0;

        #10 addr = 32'b;

        

    end

    // always begin
    //     $monitor("VALID:%d  DIRTY:%d CACHE HIT:%d DATA OUT:%d\n",)
    // end

    always begin
        #10 clk = ~clk;
    end


endmodule