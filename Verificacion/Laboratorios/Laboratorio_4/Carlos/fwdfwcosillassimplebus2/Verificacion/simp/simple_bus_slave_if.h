#ifndef __simple_bus_slave_if_h
#define __simple_bus_slave_if_h

#include <systemc.h>

#include "simple_bus_types.h"
#include "simple_bus_direct_if.h"


class simple_bus_slave_if
  : public simple_bus_direct_if
{
public:
  // Slave interface
  virtual simple_bus_status read(int *data, unsigned int address) = 0;
  virtual simple_bus_status write(int *data, unsigned int address) = 0;

  virtual unsigned int start_address() const = 0;
  virtual unsigned int end_address() const = 0;

}; // end class simple_bus_slave_if

#endif
