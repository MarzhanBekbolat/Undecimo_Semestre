#ifndef TESTBENCHAND_H_
#define TESTBENCHAND_H_

#include <systemc.h>

class Testbenchand : public sc_module 
{
public:

	sc_in<bool> clk_in;
	sc_in< sc_bv<8> > Y;
	sc_out< sc_bv<8> > A;
	sc_out< sc_bv<8> > B;

	SC_CTOR(Testbenchand);

private:

	void test();
	void print();
};



#endif /* TESTBENCHAND_H_*/
