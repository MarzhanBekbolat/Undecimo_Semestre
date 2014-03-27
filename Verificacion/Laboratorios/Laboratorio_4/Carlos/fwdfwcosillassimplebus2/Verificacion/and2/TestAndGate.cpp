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
  sc_signal< sc_bv<8> > Asignal;
  sc_signal< sc_bv<8> > Bsignal;
  sc_signal< sc_bv<8> > Ysignal;
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
