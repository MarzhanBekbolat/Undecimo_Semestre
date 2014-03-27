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
 
  simple_bus_test.h : The test bench.
 
  Original Author: Ric Hilderink, Synopsys, Inc., 2001-10-11
 
 *****************************************************************************/
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/



#ifndef __simple_bus_test_h
#define __simple_bus_test_h

#include <systemc.h>
#include "simple_bus_master_blocking.h"
#include "simple_bus_master_non_blocking.h"
#include "simple_bus_master_direct.h"
#include "simple_bus_slow_mem.h"
#include "simple_bus.h"
#include "simple_bus_fast_mem.h"
#include "simple_bus_arbiter.h"
#include "simple_bus_test.h"

SC_MODULE(simple_bus_test)
{

  // channels
  sc_clock C1;

  // module instances declaracion de objetos maestros
  public:	
  simple_bus_master_blocking     *master_b1;
  simple_bus_master_blocking     *master_b2;
 // simple_bus_master_blocking     *master_b3;
  
  simple_bus_master_non_blocking *master_nb1;
  simple_bus_master_non_blocking *master_nb2;
  //simple_bus_master_non_blocking *master_nb3;
  
  simple_bus_master_direct       *master_d;
  simple_bus_slow_mem            *mem_slow;
  simple_bus                     *bus;
  simple_bus_fast_mem            *mem_fast;
  simple_bus_arbiter             *arbiter;

  // constructor 
  SC_CTOR(simple_bus_test)
    : C1("C1")
  {
//// Decalracion variables de entrada de maestros (prioridad, timeout)
int prioridad_mb1, prioridad_mb2, prioridad_mb3, prioridad_mnb1, prioridad_mnb2, prioridad_mnb3;
int timeout_mb1, timeout_mb2, timeout_mb3, timeout_mnb1, timeout_mnb2, timeout_mnb3;

cout<<" "<<endl;

cout<<"   #######..LABORATORIO 4 Verificacion de Sistemas Digitales..###### " <<endl;
cout<<" "<<endl;
cout<<"   ######···Medición de Metricas de desempeño del SIMPLE BUS···##### " <<endl;
cout<<" "<<endl;

cout<<" "<<("Ingrese prioridad del primer Maestro bloking:      ");
cin>>prioridad_mb1;
cout<<" "<<("Ingrese prioridad del segundo Maestro bloking:     ");
cin>>prioridad_mb2;
//cout<<" "<<("Ingrese prioridad del tercer Maestro bloking:     ");
//cin>>prioridad_mb3;


cout<<" "<<("Ingrese prioridad del primer Maestro non-bloking:  ");
cin>>prioridad_mnb1;
cout<<" "<<("Ingrese prioridad del segundo Maestro non-bloking: ");
cin>>prioridad_mnb2;
//cout<<" "<<("Ingrese prioridad del tercer Maestro non-bloking: ");
//cin>>prioridad_mnb3;
cout<<" "<<endl;
/*
cout<<" "<<("Ingrese el timeout para el primer Maestro bloking:     ");
cin>>timeout_mb1;
cout<<" "<<("Ingrese el timeout para el segundo Maestro bloking:    ");
cin>>timeout_mb2;
//cout<<" "<<("Ingrese el timeout para el tercer Maestro bloking:    ");
//cin>>timeout_mb3;

cout<<" "<<("Ingrese el timeout para el primer Maestro non-bloking: ");
cin>>timeout_mnb1;
cout<<" "<<("Ingrese el timeout para el segundo Maestro non-bloking:");
cin>>timeout_mnb2;
//cout<<" "<<("Ingrese el timeout para el tercer Maestro non-bloking:");
//cin>>timeout_mnb3;
*/


    // create instances
    
    ////costructor para maestros tipo blocking if (burst)
    master_b1 = new simple_bus_master_blocking("MAESTRO_1_BLOCKING", prioridad_mb1, 0x40, false, 50);//timeout_mb1);
    master_b2 = new simple_bus_master_blocking("MAESTRO_2_BLOCKING", prioridad_mb2, 0x40, false, 50);//timeout_mb2);    
  //  master_b3 = new simple_bus_master_blocking("MAESTRO_3_BLOCKING", prioridad_mb3, 0x80, true, timeout_mb3);    
    
    ////costructor para maestros tipo non blocking 
    master_nb1 = new simple_bus_master_non_blocking("MAESTRO_1_NON_BLOCKING", prioridad_mnb1, 0x80, false, 50);// timeout_mnb1);
    master_nb2 = new simple_bus_master_non_blocking("MAESTRO_2_NON_BLOCKING", prioridad_mnb2, 0x80, false, 50);//timeout_mnb2);
    //master_nb3 = new simple_bus_master_non_blocking("MAESTRO_3_NON_BLOCKING", prioridad_mnb3, 0x80, true, timeout_mnb3);
        

    master_d = new simple_bus_master_direct("Master_Direct", 0x80, 100000);
    mem_fast = new simple_bus_fast_mem("Fast_Memory", 0x00, 0x7f);
    mem_slow = new simple_bus_slow_mem("Slow_Memory", 0x80, 0xff, 5);
    //bus = new simple_bus("bus",true); // verbose output
    bus = new simple_bus("bus");
    //arbiter = new simple_bus_arbiter("arbiter",true); // verbose output
    arbiter = new simple_bus_arbiter("arbiter");

    // connect instances 
    master_d->clock(C1);
    bus->clock(C1);
    
    master_b1->clock(C1);
    master_b2->clock(C1);
    //master_b3->clock(C1);
    master_b1->bus_port(*bus);
    master_b2->bus_port(*bus);
    //master_b3->bus_port(*bus);
    
    master_nb1->clock(C1);
    master_nb2->clock(C1);
    //master_nb3->clock(C1);
    master_nb1->bus_port(*bus);
    master_nb2->bus_port(*bus);
    //master_nb3->bus_port(*bus);
    
    mem_slow->clock(C1);
    master_d->bus_port(*bus);
    
    bus->arbiter_port(*arbiter);
    bus->slave_port(*mem_slow);
    bus->slave_port(*mem_fast);
  }

  // destructor
  ~simple_bus_test()
  {
    if (master_b1) {delete master_b1; master_b1 = 0;}
    if (master_b2) {delete master_b2; master_b2 = 0;}
    //if (master_b3) {delete master_b3; master_b3 = 0;}
    
    if (master_nb1) {delete master_nb1; master_nb1 = 0;}
    if (master_nb2) {delete master_nb2; master_nb2 = 0;}
    //if (master_nb3) {delete master_nb2; master_nb2 = 0;}
        
    if (master_d) {delete master_d; master_d = 0;}
    if (mem_slow) {delete mem_slow; mem_slow = 0;}
    if (bus) {delete bus; bus = 0;}
    if (mem_fast) {delete mem_fast; mem_fast = 0;}
    if (arbiter) {delete arbiter; arbiter = 0;}
  }

}; // end class simple_bus_test

#endif
