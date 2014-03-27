#ifndef __simple_bus_master_blocking_h
#define __simple_bus_master_blocking_h

#include <systemc.h>

#include "simple_bus_types.h"
#include "simple_bus_blocking_if.h"


SC_MODULE(simple_bus_master_blocking)
{
  // ports
  sc_in_clk clock;
  sc_port<simple_bus_blocking_if> bus_port;

  SC_HAS_PROCESS(simple_bus_master_blocking);

  // constructor
  simple_bus_master_blocking(sc_module_name name_
			     , unsigned int unique_priority
			     , unsigned int address
                             , bool lock
                             , int timeout)
    : sc_module(name_)
    , m_unique_priority(unique_priority)
    , m_address(address)
    , m_lock(lock)
    , m_timeout(timeout)
  {
    // process declaration
    SC_THREAD(main_action);
    sensitive << clock.pos();
k1=1;
  }
  
  // process
  void main_action();

public:
  unsigned int m_unique_priority;
  unsigned int m_address;
  bool m_lock;
  int m_timeout;
  double lat1, thro1,laten1,k1,latotal1,throu1,thtotal1;//agregado para las metricas (variables globales) para utilizarlas en el main jlpr

}; // end class simple_bus_master_blocking

#endif
