/*
Module of adder: This module add the numbers
Input
	A: Input of signal in binary.
	BB: Input of signal in binary by operation NOT or the signal origianl.
	Z: Input of flag of the operation adder of substrac.
Output
	S: Output of the operation
	C_out: Is the carrie of Out, determine if the number is positive higher of the limit of bits obtain out 1, but if the number is positive but of substrac indicate a negative number.
David Ricardo Martinez Hernandez  drmartinezhe@unal.edu.co
Sergio Andrés Zapata Palomino     sazapatap@unal.edu.co
*/
#include "systemc.h"
SC_MODULE(adder){
	sc_in<sc_bv<8> > A, BB;
	sc_out<sc_bv<8> > S;
	sc_uint<8> A_int, BB_int, C_out_int;
	sc_uint<8> S_int;
	sc_in<bool> Z;
	sc_out<bool> C_out;
	void do_adder(){//do_adder name of void
		A_int=A.read();
		BB_int=BB.read();
		if (Z == true){ //resta
			BB_int=99999999-BB_int; //Realice the operatión not			
			if (A_int >= BB_int) {
				S_int=A_int-BB_int; // if the substrac is positive
				C_out_int=0;
			}
			else {
				S_int=BB_int-A_int; // B>A
				C_out_int=1;        // number positive adn C_out is 1
			}
		}
		else {//for the add
			S_int=A_int+BB_int;	
			if(S_int > 255){
				S_int=0;
				C_out_int=1;
			}
			else {
			S_int;
			}
		}
		C_out=C_out_int;
		S=S_int;
	}
	SC_CTOR(adder){
		SC_METHOD(do_adder);
		sensitive <<A<<BB<<Z;
	}
};
