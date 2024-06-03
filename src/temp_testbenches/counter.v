`timescale 1ns / 1ps
// A general purpose parameterized, for size, counter with hold.

module counter #(parameter size=8) (reset, clk, hold, cntr);
  input reset, clk, hold;
  output reg [size-1:0] cntr;

  always @ (posedge clk or posedge reset)
  begin
    if(reset)
    begin
      cntr <= 0;
    end
    else
    if(hold)
    begin
      cntr <= cntr;
    end
    else
    begin
      cntr <= cntr + 1'b1;
    end 
  end
endmodule