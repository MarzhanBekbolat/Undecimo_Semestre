#ifndef __simple_bus_blocking_if_h
#define __simple_bus_blocking_if_h

#include <systemc.h>

#include "simple_bus_types.h"

class simple_bus_blocking_if
  : public virtual sc_interface
{
public:
  // blocking BUS interface
  virtual simple_bus_status burst_read(unsigned int unique_priority
				       , int *data
				       , unsigned int start_address
				       , unsigned int length = 1
				       , bool lock = false) = 0;
  virtual simple_bus_status burst_write(unsigned int unique_priority
					, int *data
					, unsigned int start_address
					, unsigned int length = 1
					, bool lock = false) = 0;

}; // end class simple_bus_blocking_if

#endif
