#ifndef __simple_bus_non_blocking_if_h
#define __simple_bus_non_blocking_if_h

#include <systemc.h>

#include "simple_bus_types.h"

class simple_bus_non_blocking_if
  : public virtual sc_interface
{
public:
  // non-blocking BUS interface
  virtual void read(unsigned int unique_priority
		    , int *data
		    , unsigned int address
		    , bool lock = false) = 0;
  virtual void write(unsigned int unique_priority
		     , int *data
		     , unsigned int address
		     , bool lock = false) = 0;

  virtual simple_bus_status get_status(unsigned int unique_priority) = 0;

}; // end class simple_bus_non_blocking_if

#endif
