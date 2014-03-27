/*
Module of multiplexor 2.
Input
	in1: This the output of the operation AND
	in2: This the output of the operation OR
	in3: This the output of the adder
	in4: This the output of the extend zero
	F: This the signal of control, determine the output
Output
	Y: This the output
David Ricardo Martinez Hernandez  drmartinezhe@unal.edu.co
Sergio Andrés Zapata Palomino     sazapatap@unal.edu.co
*/
#include "systemc.h"

SC_MODULE(mux2){
	sc_in<sc_bv<8> > in1 , in2, in3, in4;
	sc_in<sc_bv<2> > F;
	sc_out<sc_bv<8> > Y;
	void do_mux2(){
		if (F.read()==0b00){//out of and
			Y.write(in1.read());
		}
		else if (F.read()==0b01){//out of or
			Y.write(in2.read());
		}
		else if (F.read()==0b10){//out of adder
			Y.write(in3.read());
		}
		else if (F.read()==0b11){//out of extend zero
			Y.write(in4.read());
		}
	}
	SC_CTOR(mux2){
		SC_METHOD(do_mux2);
		sensitive <<in1<<in2<<in3<<F;
	}
};
