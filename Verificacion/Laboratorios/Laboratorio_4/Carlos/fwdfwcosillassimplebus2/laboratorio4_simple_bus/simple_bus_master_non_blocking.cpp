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
 
  simple_bus_master_non_blocking.cpp : The master using the non-blocking BUS
                                       interface.
 
  Original Author: Ric Hilderink, Synopsys, Inc., 2001-10-11
 
 *****************************************************************************/
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/


#include "simple_bus_master_non_blocking.h"
#include "latencia.h"
#include "troughtput.h"

void simple_bus_master_non_blocking::main_action()
{
  int mydata;
  int cnt = 0;
  unsigned int addr = m_start_address;
   latencia latencia_non_blocking;
   troughtput troughtput_non_blocking;
double current_time_n,tiempo_tro;
cont_nivel_nb=3;
	
  wait(); // ... for the next rising clock edge
  while (true)
    {
     if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_WAIT)
{
	  time_count = sc_time_stamp().to_double();//para pasar el tiempo sc_time_stamp() a double
}

      bus_port->read(m_unique_priority, &mydata, addr, m_lock);
      while ((bus_port->get_status(m_unique_priority) != SIMPLE_BUS_OK) &&
	     (bus_port->get_status(m_unique_priority) != SIMPLE_BUS_ERROR))
		wait();

      if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : ERROR cannot read from %x\n",
		   sc_time_stamp().to_double(), name(), addr);

      mydata = cnt;
      cnt++;
  //   if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_WAIT)
//{
current_time_n = sc_time_stamp().to_double(); 
time_count= current_time_n - time_count;
//}
      bus_port->write(m_unique_priority, &mydata, addr, m_lock);
      while ((bus_port->get_status(m_unique_priority) != SIMPLE_BUS_OK) &&
	     (bus_port->get_status(m_unique_priority) != SIMPLE_BUS_ERROR))
	wait();




      if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : ERROR cannot write to %x\n",
		   sc_time_stamp().to_double(), name(), addr);
 

	  if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_OK){////transferencia finalizada
tiempo_tro=(sc_time_stamp().to_double());//-current_time_n; 

		sb_fprintf(stdout,name());
		cont_nb++;	  		
		cont_nivel_nb++;
		latency_nb=latencia_non_blocking.medir_latencia_n(time_count,cont_nb);
		troughtput_nb=troughtput_non_blocking.medir_troughtput_n(tiempo_tro);

	  }





      wait(m_timeout, SC_NS);
      wait(); // ... for the next rising clock edge

      addr+=4; // next word (byte addressing)
      if (addr > (m_start_address+0x80)) {
        addr = m_start_address; cnt = 0;
      }
    }
}
