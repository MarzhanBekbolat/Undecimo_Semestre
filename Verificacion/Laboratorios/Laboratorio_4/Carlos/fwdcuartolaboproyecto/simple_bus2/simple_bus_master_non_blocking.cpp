#include "simple_bus_master_non_blocking.h"

void simple_bus_master_non_blocking::main_action()
{
  int mydata;
  int cnt = 0;
  unsigned int addr = m_start_address;
  //double count,tdume,tdumetot,tdumenonblock, tdumeinir, tdumefinr, tdumer, tdumeiniw, tdumefinw, tdumew;



  wait(); // ... for the next rising clock edge
  while (true)
    {
          lat = sc_time_stamp().to_double();        //convierte el tiempo sc_time_stamp() a double
          tdumeinir=sc_time_stamp().to_double();


      bus_port->read(m_unique_priority, &mydata, addr, m_lock);
      while ((bus_port->get_status(m_unique_priority) != SIMPLE_BUS_OK) &&
	     (bus_port->get_status(m_unique_priority) != SIMPLE_BUS_ERROR))
	wait();

      if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_OK)
	sb_fprintf(stdout, "%g %s : ERROR cannot read from %x\n",
		   sc_time_stamp().to_double(), name(), addr);

        tdumefinr=sc_time_stamp().to_double();
	tdumer=tdumefinr-tdumeinir;

      mydata += cnt;
      cnt++;

      lat = sc_time_stamp().to_double() - lat;      //se obtiene la latencia de cada maestro
      

      bus_port->write(m_unique_priority, &mydata, addr, m_lock);
      while ((bus_port->get_status(m_unique_priority) != SIMPLE_BUS_OK) &&
	     (bus_port->get_status(m_unique_priority) != SIMPLE_BUS_ERROR))
	wait();


                tdumefinw=sc_time_stamp().to_double();
	        tdumew=tdumefinw-tdumeiniw;
	       
	
         	count += 1;
	        tdume=tdumer+tdumew;
	        tdumetot += tdume;
	        tdumenonblock=tdumetot/(2*count);
	        sb_fprintf(stdout, " \n contador: %g \t tdume: %g \t tdume total: %g \t tdume non_blocking: %g \n",count,tdume,tdumetot,tdumenonblock);



     //metricas de cada maestro 

	  if (bus_port->get_status(m_unique_priority) == SIMPLE_BUS_OK){
	  	
	  	lat /= 1000;    //se debe al tiempo de simulacion del test
		laten+=lat;
		k++;
		laten_total=(laten/k)/5;

	  	thro = 32;     //se debe al tamaño de la memoria para almacenar datos
		throu += thro;
		through_total=throu*1000/sc_time_stamp().to_double();
		sb_fprintf(stdout, "%g\tLatencia:%g\tThroughput:%g\t%s: Escritura del maestro Non-Blocking \n",//para imprimir en pantalla 
		sc_time_stamp().to_double(), laten_total, through_total, name());


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
