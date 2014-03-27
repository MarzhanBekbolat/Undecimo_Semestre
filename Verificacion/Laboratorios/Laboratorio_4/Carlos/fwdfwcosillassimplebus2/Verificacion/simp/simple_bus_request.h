#ifndef __simple_bus_request_h
#define __simple_bus_request_h

enum simple_bus_lock_status { SIMPLE_BUS_LOCK_NO = 0
			      , SIMPLE_BUS_LOCK_SET
			      , SIMPLE_BUS_LOCK_GRANTED 
};

struct simple_bus_request
{
  // parameters
  unsigned int priority;

  // request parameters
  bool do_write;
  unsigned int address;
  unsigned int end_address;
  int *data;
  simple_bus_lock_status lock;

  // request status
  sc_event transfer_done;
  simple_bus_status status;

  // default constructor
  simple_bus_request();
};

inline simple_bus_request::simple_bus_request()
  : priority(0)
  , do_write(false)
  , address(0)
  , end_address(0)
  , data((int *)0)
  , lock(SIMPLE_BUS_LOCK_NO)
  , status(SIMPLE_BUS_OK)
{}

#endif
