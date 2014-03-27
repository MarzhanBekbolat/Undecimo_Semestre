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
