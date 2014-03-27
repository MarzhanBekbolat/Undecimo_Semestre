#include "systemc.h"
#include "simple_bus_test.h" 

simple_bus_test top("top");



int sc_main(int, char **)
{
//para que se vea bien jlpr
  cout<<endl;
  cout<<" "<<("Escriba el tiempo de simulación:   ");
 
//tiempo de simulación jlpr
  int TS;
  cin>>TS;
  sc_start(TS, SC_NS);    
//para tomar las variables al final de la simulacion jlpr

  while (sc_time_stamp().to_double()/1000<TS){}

//metricas totales jlpr 
cout<<endl;
  cout<<"      ======= Métricas de Desempeño ======="<<endl<<endl;
  double latenciaMedia=(top.master_b->latotal1+top.master_nb->latotal+top.master_b1->latotal1+top.master_nb1->latotal)/4.0;
  cout<<"      Latencia Media:      "<<latenciaMedia<<" ns"<<endl;
  double throup=(top.master_b->thtotal1+top.master_nb->thtotal+top.master_b1->thtotal1+top.master_nb1->thtotal)/4.0;
  cout<<"      Throughput:          "<<throup<<" words/ciclo"<<endl;
  double eficiencia=(top.bus->utilizacion);
  cout<<"      Eficiencia del bus:  "<<eficiencia<<" %"<<endl;
  cout<<endl;
 

return 0;
}







