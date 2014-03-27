#ifndef ANDGATE_H_
#define ANDGATE_H_

#include <systemc.h>

class AndGate : public sc_module
{
 public:
  sc_in< sc_bv<4> > A;
  sc_in< sc_bv<4> > B;
  sc_out< sc_bv<4> > Y;

  SC_CTOR(AndGate);
  
 private:
  void opand();
};

#endif /*ANDGATE_H_*/

#include "AndGate.h"

AndGate::AndGate(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(opand);
	sensitive << A << B;
}

void AndGate::opand()
{
  Y.write(A.read() & B.read());
}

#ifndef TESTBENCHAND_H_
#define TESTBENCHAND_H_

#include <systemc.h>

class Testbenchand : public sc_module 
{
public:

	sc_in<bool> clk_in;
	sc_in< sc_bv<4> > Y;
	sc_out< sc_bv<4> > A;
	sc_out< sc_bv<4> > B;

	SC_CTOR(Testbenchand);

private:

	void test();
	void print();
};



#endif /* TESTBENCHAND_H_*/

# include "Testbenchand.h"

Testbenchand::Testbenchand(sc_module_name nm) : sc_module(nm)
{
	SC_THREAD(test);
	sensitive << clk_in.pos();
	dont_initialize();
}

void Testbenchand::print() {
	cout << sc_time_stamp()
		 << "\t " << A.read()
		 << "\t " << B.read()
		 << "\t " << Y.read()
		 << endl;
}

void Testbenchand::test()
{
	cout << "Time\t A\t\t B\t\t\t Y"<<endl;
	cout<< "--------------------------------------------"<<endl;
		

	A.write(1001);
	B.write(1010);

	wait();


	A.write(1000);
	B.write(1011);

	wait();

	print();

	sc_stop();
}


