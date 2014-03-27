#ifndef __simple_bus_types_h
#define __simple_bus_types_h

#include <stdio.h>
#include <systemc.h>

enum simple_bus_status { SIMPLE_BUS_OK = 0
			 , SIMPLE_BUS_REQUEST
			 , SIMPLE_BUS_WAIT
			 , SIMPLE_BUS_ERROR };

// needed for more readable debug output
extern char simple_bus_status_str[4][20]; 

struct simple_bus_request;
typedef sc_pvector<simple_bus_request *> simple_bus_request_vec;

extern int sb_fprintf(FILE *, const char *, ...);

#endif
