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

#include "AndGate.h"
#include "Testbenchand.h"


int sc_main(int argc, char * argv[]) 
{
  sc_set_time_resolution(1, SC_PS);
  sc_time Period(10, SC_PS);
  //Retraso para el primer flanco positivo del reloj
  sc_time Delay(5, SC_PS);//esta linea no esta en el ejemplo

  //Instanciación del sistema
  AndGate and0("and0");
  Testbenchand test0("stimulus");//Diferente
  
  //Señales
  sc_signal< sc_bv<4> > Asignal;
  sc_signal< sc_bv<4> > Bsignal;
  sc_signal< sc_bv<4> > Ysignal;
  sc_clock clk("clock", Period, 0.5, Delay, true);
  
  //Conecciones entre los módulos
  test0.A(Asignal);
  test0.B(Bsignal);
  test0.Y(Ysignal);   
  test0.clk_in(clk);
  
  and0.A(Asignal);
  and0.B(Bsignal);
  and0.Y(Ysignal);
  
  
  //Creación de un trace file
  sc_trace_file *tf;
  tf = sc_create_vcd_trace_file("traceAndGate");
  tf->set_time_unit(1, SC_PS);	
  sc_trace(tf, clk, "Clock");
  sc_trace(tf, Asignal, "Asignal");
  sc_trace(tf, Bsignal, "Bsignal");
  sc_trace(tf, Ysignal, "Ysignal");	
  
  //Inicio de la simulación
  sc_start();

  //Cierre del "trace file"
  sc_close_vcd_trace_file(tf); 
  
  return 0;
}
