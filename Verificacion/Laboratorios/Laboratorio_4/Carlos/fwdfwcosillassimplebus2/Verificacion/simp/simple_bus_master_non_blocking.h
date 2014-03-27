#ifndef __simple_bus_master_non_blocking_h
#define __simple_bus_master_non_blocking_h

#include <systemc.h>

#include "simple_bus_types.h"
#include "simple_bus_non_blocking_if.h"


SC_MODULE(simple_bus_master_non_blocking)
{
  // ports
  sc_in_clk clock;
  sc_port<simple_bus_non_blocking_if> bus_port;

  SC_HAS_PROCESS(simple_bus_master_non_blocking);

  // constructor
  simple_bus_master_non_blocking(sc_module_name _name
				 , unsigned int unique_priority
                                 , unsigned int start_address
                                 , bool lock
                                 , int timeout)
    : sc_module(_name)
    , m_unique_priority(unique_priority)
    , m_start_address(start_address)
    , m_lock(lock)
    , m_timeout(timeout)
  {
    // process declaration
    SC_THREAD(main_action);
    sensitive << clock.pos();
k=1;
  }
  
  // process
  void main_action();

public:
  unsigned int m_unique_priority;
  unsigned int m_start_address;
  bool m_lock;
  int m_timeout;
  double lat, thro,k,latotal,throu,thtotal,laten;// variables globales para utilizarlas en al main jlpr

}; // end class simple_bus_master_non_blocking

#endif