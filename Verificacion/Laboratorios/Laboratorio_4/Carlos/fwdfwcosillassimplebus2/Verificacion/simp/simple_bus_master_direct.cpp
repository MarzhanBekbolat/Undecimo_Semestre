
#include "simple_bus_master_direct.h"
#include "simple_bus_types.h"


void simple_bus_master_direct::main_action()
{
 

  int mydata[4];
  while (true)
    {


      bus_port->direct_read(&mydata[0], m_address);
      bus_port->direct_read(&mydata[1], m_address+4);
      bus_port->direct_read(&mydata[2], m_address+8);
      bus_port->direct_read(&mydata[3], m_address+12);

      if (m_verbose)
      	sb_fprintf(stdout, "%g %s : mem[%x:%x] = (%x, %x, %x, %x)\n",
		      sc_time_stamp().to_double(), name(), m_address, 
		      m_address+15, 
		      mydata[0], mydata[1], mydata[2], mydata[3]);

      wait(m_timeout, SC_NS);
    }
}
