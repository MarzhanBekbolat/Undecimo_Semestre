`timescale 1ns / 1ps



module adc_top #(
		parameter N = 8
	)(
		output reg [N-1:0]percent,
		output reg sat,
		
		input [N-1:0] adc_data
    );
	
	/*
	Rango a considerar está entre MIN Y MAX,
	con longitud MAX. Para facilidad de cálculos 
	RANGE debe ser un divisor de 100
	*/
	
	parameter MIN = 'b0;
	parameter DIV = 4;
	parameter RANGE = 100 / DIV;
	parameter MAX = MIN + RANGE;
	
	initial begin
		percent = 0;
		sat = 0;
	end

	always@(*) begin
		if (adc_data < MIN) begin
			percent = 0;
			sat = 1;
		end
		
		else if (adc_data > MAX) begin
			percent = 100;
			sat = 1;
		end
		
		else begin
			percent = adc_data * DIV;
			sat = 0;
		end
	end


endmodule
