/*
Module of adder: This module realice the operation AND. 
Input
	in1: Input of signal A
	in2: Input of signal B or BB
Output
	out: Result of the operation and of signals.
David Ricardo Martinez Hernandez  drmartinezhe@unal.edu.co
Sergio Andrés Zapata Palomino     sazapatap@unal.edu.co
*/
#include "systemc.h"

SC_MODULE(andp){
	sc_in<sc_bv<8> > in1 , in2;
	sc_out<sc_bv<8> >  out;
	sc_int<8> in1_int, in2_int, out_int;
	void do_and(){
		in1_int = in1.read();
		in2_int = in2.read();
		out_int = in1_int & in2_int;
		out = out_int;
	}
	SC_CTOR(andp){
		SC_METHOD(do_and);
		sensitive <<in1<<in2;
	}
};
