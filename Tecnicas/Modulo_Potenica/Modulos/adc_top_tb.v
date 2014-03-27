`timescale 1ns / 1ps

module adc_top_tb;

	// Inputs
	reg [7:0] adc_data;

	// Outputs
	wire [7:0]percent;
	wire sat;

	// Instantiate the Unit Under Test (UUT)
	adc_top uut (
		.percent(percent), 
		.sat(sat), 
		.adc_data(adc_data)
	);

	initial begin
		// Initialize Inputs
		adc_data = 0;

		// Wait 100 ns for global reset to finish
		#100;		
		adc_data = 30;
		
		# 100
		adc_data = 234;
		
		# 200
		adc_data = 40;
		
		#100
		adc_data = 50;
		
		#100
		adc_data = 51;
		
		#100
		adc_data = 1;
        
		// Add stimulus here

	end
      
endmodule

