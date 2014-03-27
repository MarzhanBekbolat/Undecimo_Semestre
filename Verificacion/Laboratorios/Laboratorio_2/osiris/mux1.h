/* 
Module of multiplexor 1.
Input
	in: Input of multiplexor
	f2: Signal of selection for in or -in
Output
	out: Output of in or -in
	Z: Flag detemrine the operation adder or substrac.
David Ricardo Martinez Hernandez  drmartinezhe@unal.edu.co
Sergio Andrés Zapata Palomino     sazapatap@unal.edu.co
*/
#include "systemc.h"
SC_MODULE(mux1){
	sc_in<sc_bv<8> > in;
	sc_in<bool>f2;
	sc_out<sc_bv<8> > out;
	sc_out<bool> Z;
	sc_int<8> in_int;
	void do_mux1(){
		in_int=in.read();
		if (f2.read()){
			out=99999999-in_int;
			Z=true;
		}
		else{
			out=in;
			Z=false;
		}	
	}
	SC_CTOR(mux1){
		SC_METHOD(do_mux1);
		sensitive <<in<<f2;
	}
};
