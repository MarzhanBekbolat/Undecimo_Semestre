/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2006 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************
 
  simple_bus_main.cpp : sc_main
 
  Original Author: Ric Hilderink, Synopsys, Inc., 2001-10-11
 
 *****************************************************************************/
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/


#include "systemc.h"
#include "simple_bus_test.h" 


simple_bus_test top("top");


int sc_main(int, char **)
{

double latencia_promedio_b, latencia_promedio_nb, tiempo_sim;
double ocupacion,num_sim;//,contador1, contador;
int throughput_promedio_b, throughput_promedio_nb;

//  cout<<endl;
  //cout<<" "<<("Escriba El numero de Simulaciones:   ");
 

  num_sim=500;
ocupacion=num_sim;
sc_start(num_sim, SC_NS);    

//ocupacion=n_u.ocupado;
 //nivel_util=n_u.utilizacion(cont);



  //while (sc_time_stamp().to_double()/1000<tiempo_sim){}

 latencia_promedio_b=(top.master_b1->latency_b+top.master_b2->latency_b)/3;//+top.master_b3->latency_b)/3;
 latencia_promedio_nb=(top.master_nb1->latency_nb+top.master_nb2->latency_nb)/3;//+top.master_nb3->latency_nb)/3;
double latencia_prom_total= (latencia_promedio_b+latencia_promedio_nb)/2;

 throughput_promedio_b=((top.master_b1->troughtput_burst)+(top.master_b2->troughtput_burst))/2;//+(top.master_b3->troughtput_burst))/3.0;
 throughput_promedio_nb=((top.master_nb1->troughtput_nb)+(top.master_nb2->troughtput_nb))/2;//+(top.master_nb3->troughtput_nb))/3.0;
double throughput_prom_total=(throughput_promedio_b + throughput_promedio_nb);//(2*1.75);
double para_nivel=(throughput_promedio_b + throughput_promedio_nb)/(2*1.75);


//double throughput_prom_total=((top.master_b1->troughtput_burst)+(top.master_b2->troughtput_burst))+((top.master_nb1->troughtput_nb)+(top.master_nb2->troughtput_nb));
double contador1=3*(top.master_b1->cont_nivel_b+top.master_b2->cont_nivel_b+top.master_nb1->cont_nivel_nb+top.master_nb2->cont_nivel_nb);
double desoc=(top.bus->des);

 double nivel=10*(para_nivel/2);///contador1)/ocupacion;
double latencia_mb1=top.master_b1->latency_b;
double latencia_mb2=top.master_b2->latency_b;
double latencia_mnb1=top.master_nb1->latency_nb;
double latencia_mnb2=top.master_nb2->latency_nb;


 
  cout<<endl;
  cout<<"    #############.....Medidas Métricas de Desempeño.....##############"<<endl<<endl;
  
  cout<<"      Latencia Promedio Blocking1:      "<<latencia_mb1<<" ciclos"<<endl;
  cout<<"      Latencia Promedio Blocking2:      "<<latencia_mb2<<" ciclos"<<endl;
  cout<<"      Latencia Promedio Non-Blocking1:  "<<latencia_mnb1<<" ciclos"<<endl;
  cout<<"      Latencia Promedio Non-Blocking2:  "<<latencia_mnb2<<" ciclos"<<endl<<endl;
  
  //cout<<"      Throughput Promedio Blocking:      "<<throughput_promedio_b<<" words/ciclo"<<endl;
  //cout<<"      Throughput Promedio Non Blocking:  "<<throughput_promedio_nb<<" words/ciclo"<<endl<<endl;
  cout<<"      Throughput Promedio Total          "<<throughput_prom_total<<" bits/ciclo"<<endl;
 
//double eficiencia=(top.bus->utilizacion);
cout<<"      nivel de utilizacion:  "<<nivel<<" %"<<endl;
  cout<<endl;
 

return 0;
}






