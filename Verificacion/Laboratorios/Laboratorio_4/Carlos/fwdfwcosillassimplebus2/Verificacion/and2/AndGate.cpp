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
