// A general purpose parameterized, for size, counter with hold.

module counter #(parameter size=8) (reset, clk, hold, counter);
  input reset, clk, hold;
  output reg [size-1:0] counter;

  always @ (posedge clk or posedge reset)
  begin
    if(reset)
    begin
      counter <= 0;
    end
    else
    if(hold)
    begin
      counter <= counter;
    end
    else
    begin
      counter <= counter + 1'b1;
    end 
  end
endmodule