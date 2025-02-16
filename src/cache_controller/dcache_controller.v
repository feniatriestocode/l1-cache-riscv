// `timescale 1ns / 1ps

`include "../include/constants.vh"
//`include "counter.v"

module dcache_controller(input clock,
                         input reset,
                         
                         // pipeline inputs
                         input ren, wen,
                         input [(`DADDR_SIZE-1):0] addr,
                         input [(`DWORD_SIZE-1):0] byteSelectVector,
                         input [(`DWORD_SIZE_BITS-1):0] din,
                         
                         // cache inputs
                         input cacheHit,
                         input cacheDirtyBit,
                         input [(`DBLOCK_SIZE_BITS-1):0] cacheDout,
                         
                         // memory inputs
                         input memReadReady, memWriteDone,
                         input [(`DBLOCK_SIZE_BITS-1):0] memDout,
                         
                         // pipeline outputs
                         output reg stall,
                         output [(`DWORD_SIZE_BITS-1):0] dout,
 
                         //both cache and memory output
                         output [(`DMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr,
 
                         // cache outputs
                         output cacheRen, cacheWen,
                         output reg cacheMemWen,
                         output reg [(`DBLOCK_SIZE-1):0] cacheBytesAccess,
                         output reg [(`DBLOCK_SIZE_BITS-1):0] cacheDin,
                         
                         // memory outputs
                         output reg memRen, memWen,
                         output [(`DBLOCK_SIZE_BITS-1):0] memDin);
    
    
    wire pipeline_req;
    reg replace;
    wire [(`DBLOCK_OFFSET_SIZE-1):0] blockOffset;
    
    assign pipeline_req = (ren && ~wen) || (wen && ~ren);
    
    assign BlockAddr = addr[(`DADDR_SIZE-1):`DBLOCK_OFFSET_SIZE];
    assign blockOffset = addr[`DBLOCK_OFFSET_SIZE-1:0];
    
    // Read hit
    assign cacheRen = reset && ren && ~wen;
    assign dout = reset ? (cacheDout[(blockOffset[(`DBLOCK_OFFSET_SIZE-1):`DWORD_OFFSET_SIZE])*`DWORD_SIZE_BITS +:`DWORD_SIZE_BITS]) : {`DWORD_SIZE_BITS{1'b0}}; 
    
    // Write hit
    assign cacheWen = reset && wen && ~ren;
    
    always @(byteSelectVector or blockOffset or reset) begin
        if(~reset) begin
            cacheBytesAccess = {(`DBLOCK_SIZE){1'b0}};
        end else begin
            cacheBytesAccess = {(`DBLOCK_SIZE){1'b0}};
            cacheBytesAccess[blockOffset[(`DBLOCK_OFFSET_SIZE-1):`DWORD_OFFSET_SIZE] * `DWORD_SIZE +: `DWORD_SIZE] = byteSelectVector;
        end
    end
    
    always @(cacheMemWen or memDout or blockOffset or reset or din or replace) begin
        if(~reset) begin
            cacheDin = {(`DBLOCK_SIZE_BITS){1'b0}};
        end else begin
            if (cacheMemWen) begin
                cacheDin = memDout;
            end else if(replace) begin
                cacheDin = {(`DBLOCK_SIZE_BITS){1'b0}};
                cacheDin[blockOffset[(`DBLOCK_OFFSET_SIZE-1):`DWORD_OFFSET_SIZE] * `DWORD_SIZE_BITS +: `DWORD_SIZE_BITS] = din;
            end else begin
                cacheDin = {(`DBLOCK_SIZE_BITS){1'b0}};
                cacheDin[blockOffset[(`DBLOCK_OFFSET_SIZE-1):`DWORD_OFFSET_SIZE] * `DWORD_SIZE_BITS +: `DWORD_SIZE_BITS] = din;
            end
        end
    end
    
    assign memDin = cacheDout;
    
    //****************************************DCACHE MISS FSM****************************************//
    
    parameter IDLE              = 3'b000,
              WRITEBACK         = 3'b001,
              MEMREAD           = 3'b010,
              MEMCACHE          = 3'b011,
              WRITEBACK_REPLACE = 3'b100;
    
    reg [2:0] state, next_state;
    
    //SEQUENTIAL LOGIC
    always @(posedge clock or negedge reset)
    begin
    	if (reset == 1'b0) begin
            state <= IDLE;
    	end
    	else begin
            state <= next_state;
        end
    end
    
    //COMBINATIONAL LOGIC
    always @(state or pipeline_req or cacheHit or cacheDirtyBit or memWriteDone or memReadReady or ren or wen)
    begin
    	case (state)
    	    IDLE: begin
    	    	if(pipeline_req && !cacheHit) begin
                    if(cacheDirtyBit == 1'b1) begin
                        next_state = WRITEBACK;
                    end else begin
                        next_state = MEMREAD;
                    end
                end
                else begin 
                    next_state = IDLE;
                end 
    	    end
            WRITEBACK: begin
                if(memWriteDone==1) begin
                    next_state = MEMREAD;
                end
                else begin
                    next_state = WRITEBACK;
                end
    	    end 
    	    MEMREAD: begin
                if(memReadReady==1) begin
                    next_state = MEMCACHE;
                end
                else begin
                    next_state = MEMREAD;
                end
    	    end
    	    MEMCACHE: begin
                 if(wen && ~ren) begin
                    next_state = WRITEBACK_REPLACE;
                end
                else begin
                    next_state = IDLE;
                end
    	    end
            WRITEBACK_REPLACE: begin
                next_state = IDLE;
            end
            default: next_state = IDLE;
        endcase
    end
    
    //COMBINATIONAL LOGIC FOR OUTPUTS

    always @(state or pipeline_req or cacheHit or cacheDirtyBit or memWriteDone or memReadReady)
    begin
        stall = 1'b0;
        cacheMemWen = 1'b0;
        memRen = 1'b0;
        memWen = 1'b0;
        replace = 1'b0;

    	case (state)
            IDLE: begin
                stall = 1'b0;
                cacheMemWen = 1'b0;
                memRen = 1'b0;
                memWen = 1'b0;
                replace = 1'b0;
            end
            WRITEBACK: begin
                stall = 1'b1;
                memWen = 1'b1;
            end
            MEMREAD: begin
                stall = 1'b1;
                memRen = 1'b1;
            end
            MEMCACHE: begin
                stall = 1'b1;
                cacheMemWen = 1'b1;
            end
            WRITEBACK_REPLACE: begin
                stall = 1'b1;
                replace = 1'b1;
            end
        endcase
    end               
endmodule