/*

David Ricardo Martinez Hernandez  drmartinezhe@unal.edu.co
Sergio Andrés Zapata Palomino     sazapatap@unal.edu.co
*/
#include "stim.h"
#include "mux1.h"
#include "adder.h"
#include "orp.h"
#include "andp.h"
#include "mux2.h"
#include "output.h"

int sc_main(int argc, char* argv[]) {
	sc_signal<sc_bv<8> > SigA, SigB, SigC;
	sc_signal<sc_bv<8> > SigD, SigE, SigF, Sout;
	sc_signal<sc_bv<2> > control2;
	sc_signal<bool> control, carry;
	sc_signal<bool> Z;
	sc_clock TestClk("TestClock", 1, SC_NS, 2);
	//Import the lib stim.h with inputs ans outputs
	stim stim1("Stimulus");
	stim1.A(SigA);
	stim1.B(SigB);
	stim1.C(control);
	stim1.Clk(TestClk);
	stim1.F(control2);
	stim1.sal(Sout);
	//Import the lib mux1.h with inputs ans outputs
	mux1 mux("Multiplexor");
	mux.in(SigB);
	mux.f2(control);
	mux.out(SigC);
	mux.Z(Z);
	//Import the lib adder.h with inputs ans outputs
	adder ad("Adder");
	ad.A(SigA);
	ad.BB(SigC);
	ad.S(SigD);
	ad.Z(Z);
	ad.C_out(carry);
	//Import the lib orp.h with inputs ans outputs
	orp orpp("OR");
	orpp.in1(SigA);
	orpp.in2(SigC);
	orpp.out(SigE);
	//Import the lib andp.h with inputs ans outputs
	andp andpp("AND");
	andpp.in1(SigA);
	andpp.in2(SigC);
	andpp.out(SigF);
	//Import the lib mux2.h with inputs ans outputs
	mux2 muxx("Multiplexor_2");
	muxx.in1(SigF);
	muxx.in2(SigE);
	muxx.in3(SigD);
	muxx.in4(SigD);
	muxx.Y(Sout);
	muxx.F(control2);
 /*  
   output out("Output");
	out.in1(SigA);
	out.in2(SigB);
	out.out1(Sout);
*/
	sc_trace_file *fp; 
	fp=sc_create_vcd_trace_file("simulation"); //comand for crate simulation
	//import the signal for GtkWave
	sc_trace(fp, TestClk, "clk");
	sc_trace(fp, SigA, "In1_adder");
	sc_trace(fp, SigB, "In2_adder");
	sc_trace(fp, SigD, "Out_adder");
	sc_trace(fp, SigE, "Out_OR");	
	sc_trace(fp, SigF, "Out_AND");
	sc_trace(fp, control2, "Select_Mux2");
	sc_trace(fp, Sout, "Out_Final");
	sc_trace(fp, control, "control");
	sc_trace(fp, Z, "bandera");
	sc_trace(fp, carry, "carry");
	//Start simulation
	sc_start();
	sc_close_vcd_trace_file(fp); //ending the simulation
		return (0);
}
