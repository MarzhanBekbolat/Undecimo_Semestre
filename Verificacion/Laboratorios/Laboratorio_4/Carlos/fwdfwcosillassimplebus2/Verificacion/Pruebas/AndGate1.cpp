#ifndef ANDGATE_H_
#define ANDGATE_H_

#include <systemc.h>

class AndGate : public sc_module
{
 public:
  sc_in< sc_bv<8> > A;
  sc_in< sc_bv<8> > B;
  sc_out< sc_bv<8> > Y;

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
