#include "simple_bus_master_non_blocking.h"

void simple_bus_master_non_blocking::main_action()
{
  int mydata;
  int cnt = 0;
  unsigned int addr = m_start_address;


  wait(); // ... for the next rising clock edge
  while (true)
    {
	  lat = sc_time_stamp().to_double();//para pasar el tiempo sc_time_stamp() a double


      bus_port->read(m_unique_priority, &mydata, addr, m_lock);
      while ((bus_port->get_status(m_unique_priority) != SIMPLE_BUS_OK) &&
	     (bus_port->get_status(m_unique_priority) != SIMPLE_BUS_ERROR))
		wait();

      if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : ERROR cannot read from %x\n",
		   sc_time_stamp().to_double(), name(), addr);

      mydata = cnt;
      cnt++;

//para tomar la latencia de cada maestro
lat = sc_time_stamp().to_double() - lat;

      bus_port->write(m_unique_priority, &mydata, addr, m_lock);
      while ((bus_port->get_status(m_unique_priority) != SIMPLE_BUS_OK) &&
	     (bus_port->get_status(m_unique_priority) != SIMPLE_BUS_ERROR))
	wait();

//metricas de cada maestro jlpr

	  if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_OK){
	  	
	  	lat /= 1000;
		laten+=lat;
		k++;
		latotal=laten/k;

	  	thro = 32;
		throu += thro;
		thtotal=throu*1000/sc_time_stamp().to_double();
		sb_fprintf(stdout, "%g\tLatencia:%g\tThroughput:%g\t%s: Escritura del maestro Non-Blocking \n",//para imprimir en pantalla jlpr
		sc_time_stamp().to_double(), latotal, thtotal, name());
	  }


      if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : ERROR cannot write to %x\n",
		   sc_time_stamp().to_double(), name(), addr);
 
      wait(m_timeout, SC_NS);
      wait(); // ... for the next rising clock edge

      addr+=4; // next word (byte addressing)
      if (addr > (m_start_address+0x80)) {
        addr = m_start_address; cnt = 0;
      }
    }
}
