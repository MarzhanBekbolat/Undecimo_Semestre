#ifndef __simple_bus_arbiter_h
#define __simple_bus_arbiter_h

#include <systemc.h>

#include "simple_bus_types.h"
#include "simple_bus_request.h"
#include "simple_bus_arbiter_if.h"


class simple_bus_arbiter
  : public simple_bus_arbiter_if
  , public sc_module
{
public:
  // constructor
  simple_bus_arbiter(sc_module_name name_
                     , bool verbose = false)
    : sc_module(name_)
    , m_verbose(verbose)
  {T=200;}

  simple_bus_request *arbitrate(const simple_bus_request_vec &requests);

public:
  bool m_verbose;
  int T;   //variable global para la seleccion del maestro

}; // end class simple_bus_arbiter

#endif
