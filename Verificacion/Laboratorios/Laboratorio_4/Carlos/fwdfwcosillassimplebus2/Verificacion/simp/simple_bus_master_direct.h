#ifndef __simple_bus_master_direct_h
#define __simple_bus_master_direct_h

#include <systemc.h>

#include "simple_bus_direct_if.h"


SC_MODULE(simple_bus_master_direct)
{
  // ports
  sc_in_clk clock;
  sc_port<simple_bus_direct_if> bus_port;

  SC_HAS_PROCESS(simple_bus_master_direct);

  // constructor
  simple_bus_master_direct(sc_module_name name_
                           , unsigned int address
                           , int timeout
                           , bool verbose = true)
    : sc_module(name_)
    , m_address(address)
    , m_timeout(timeout)
    , m_verbose(verbose)
  {
    // process declaration
    SC_THREAD(main_action);
  }

  // process
  void main_action();

private:
  unsigned int m_address;
  int m_timeout;
  bool m_verbose;

}; // end class simple_bus_master_direct

#endif
