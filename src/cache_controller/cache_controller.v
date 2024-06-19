//`timescale 1ns / 1ps

//`include "constants.v"
//`include "counter.v"

module dcache_controller(// pipeline inputs
                        input clock,
                        input reset,
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
                        output stall,
                        output [(`DWORD_SIZE_BITS-1):0] dout,

                        //both cache and memory output
                        output [(`DMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr,

                        // cache outputs
                        output cacheEn, cacheWen, cacheMemWen,
                        output [(`DBLOCK_SIZE-1):0] cacheBytesAccess,
                        output [(`DBLOCK_SIZE_BITS-1):0] cacheDin,
                        
                        // memory outputs
                        output memRen, memWen,
                        output [(`DBLOCK_SIZE_BITS-1):0] memDin);

  			   
wire pipeline_req;
wire [(`DBLOCK_OFFSET_SIZE-1):0] blockOffset;

assign pipeline_req = (ren && ~wen) || (wen && ~ren);

assign BlockAddr = addr[(`DMEM_BLOCK_ADDR_SIZE-1):`DBLOCK_OFFSET_SIZE];

assign blockOffset = addr[`DBLOCK_OFFSET_SIZE-1:0];

assign dout = cacheDout[blockOffset*8+:`DWORD_SIZE_BITS];


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cache Controller Logic
reg [(`DBLOCK_SIZE_BITS-1):0] cacheData;
reg [(`DBLOCK_SIZE-1):0] cacheBytesAccess;
reg [(`DBLOCK_SIZE_BITS-1):0] cacheDin;
reg cacheEn, cacheWen, cacheMemWen;

always @(posedge clock or negedge reset) begin
    if (reset == 1'b0) begin
        cacheData <= 0;
        cacheBytesAccess <= 0;
        cacheDin <= 0;
        cacheEn <= 0;
        cacheWen <= 0;
        cacheMemWen <= 0;
    end else begin
        if (cacheHit) begin
            cacheData <= cacheDout;
            cacheBytesAccess <= byteSelectVector;
            cacheEn <= 1'b1;
            cacheWen <= 1'b0;
            cacheMemWen <= 1'b0;
        end else begin
            cacheData <= cacheDin;
            cacheBytesAccess <= 0;
            cacheEn <= 1'b0;
            cacheWen <= 1'b1;
            cacheMemWen <= 1'b1;
        end
    end
end

// Memory Controller Logic
reg memRen, memWen;
reg [(`DBLOCK_SIZE_BITS-1):0] memDin;

always @(posedge clock or negedge reset) begin
    if (reset == 1'b0) begin
        memRen <= 0;
        memWen <= 0;
        memDin <= 0;
    end else begin
        if (state == MEMREAD) begin
            memRen <= 1'b1;
            memWen <= 1'b0;
            memDin <= 0;
        end else if (state == WRITEBACK) begin
            memRen <= 1'b0;
            memWen <= 1'b1;
            memDin <= cacheData;
        end else begin
            memRen <= 1'b0;
            memWen <= 1'b0;
            memDin <= 0;
        end
    end
end

// Output Assignments
assign dout = cacheData;
assign BlockAddr = addr[`DMEM_BLOCK_ADDR_SIZE-1:0];
assign cacheBytesAccess = cacheBytesAccess;
assign cacheDin = cacheDin;
assign cacheEn = cacheEn;
assign cacheWen = cacheWen;
assign cacheMemWen = cacheMemWen;
assign memRen = memRen;
assign memWen = memWen;
assign memDin = memDin;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//-----------------------FSM----------------------------------------//

parameter IDLE = 3'b000,
          MISS = 3'b001,
          MEMREAD = 3'b010,
          WRITEBACK = 3'b011,
          MEMCACHE = 3'b100;


reg [2:0 ]state, next_state;
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
always @(state, pipeline_req, cacheHit, cacheDirtyBit, memWriteDone, memReadReady)
begin
	case (state)
	IDLE: begin
		if(pipeline_req && !cacheHit) begin
            next_state = MISS;
        end
        else begin 
            next_state = IDLE;
        end
	end
	MISS: begin
        if(cacheDirtyBit == 1'b1) begin
            next_state = WRITEBACK;
        end
        else begin
        next_state = MEMREAD;
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
	WRITEBACK: begin
        if(memWriteDone==1) begin
            next_state = MEMREAD;
        end
        else begin
        next_state = WRITEBACK;
        end
	end
	MEMCACHE: begin
        next_state = IDLE;
	end
    default: next_state = IDLE;
    endcase
end

	
//COMBINATIONAL LOGIC FOR OUTPUTS

always @(state,pipeline_req, cacheHit, cacheDirtyBit, memWriteDone, memReadReady)
begin
    stall = 1'b0;
    cacheEn = 1'b0;
    cacheWen = 1'b0; 
    cacheFullblockWen = 1'b0;
    memRen = 1'b0;
    memWen = 1'b0;
	case (state)
	MISS: begin
       stall = 1'b1;
	end
	MEMREAD: begin
        stall = 1'b1;
        memRen = 1'b1;
	end
	WRITEBACK: begin
       stall = 1'b1;
       memWen = 1'b1;
	end
	MEMCACHE: begin
       stall = 1'b1;
       cacheEn = 1'b1;
       cacheWen = 1'b1; 
       cacheFullblockWen = 1'b1;
	end
    endcase
end

                        
endmodule
