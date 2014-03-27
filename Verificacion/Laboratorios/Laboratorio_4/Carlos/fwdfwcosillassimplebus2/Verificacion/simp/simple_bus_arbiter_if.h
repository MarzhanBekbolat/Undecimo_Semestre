#ifndef __simple_bus_arbiter_if_h
#define __simple_bus_arbiter_if_h

#include <systemc.h>

#include "simple_bus_types.h"


class simple_bus_arbiter_if
  : public virtual sc_interface
{
public:
  virtual simple_bus_request * 
    arbitrate(const simple_bus_request_vec &requests) = 0;

}; // end class simple_bus_arbiter_if

#endif
