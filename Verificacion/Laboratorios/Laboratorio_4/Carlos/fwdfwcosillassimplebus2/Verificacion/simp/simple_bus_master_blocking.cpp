#include "simple_bus_master_blocking.h"

 void simple_bus_master_blocking::main_action()
{
  const unsigned int mylength = 0x06; // storage capacity/burst length in words
  int mydata[mylength];
  unsigned int i;
  
  simple_bus_status status;

  while (true)
    {
      wait(); // ... for the next rising clock edge
     

 lat1 = sc_time_stamp().to_double();//para pasar el tiempo sc_time_stamp() a double


      status = bus_port->burst_read(m_unique_priority, mydata, 
				    m_address, mylength, m_lock);
	 

      if (status == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : blocking-read failed at address %x\n",
		   sc_time_stamp().to_double(), name(), m_address);

      for (i = 0; i < mylength; ++i)
	{
	  mydata[i] = 1;
	  wait();
	}

	  lat1 = sc_time_stamp().to_double()-lat1;//para calcular la latencia de cada maestro jlpr


      status = bus_port->burst_write(m_unique_priority, mydata, 
				     m_address, mylength, m_lock);


//para calcular las metricas:	  
	if (status == SIMPLE_BUS_OK){
	  	
//metricas de cada maestro jlpr
	  	lat1 /= 1000;
                laten1+=lat1;
		k1++;
		latotal1=laten1/k1;

	  	thro1 = (32 * mylength)*1000/sc_time_stamp().to_double();
		throu1 += thro1;
		thtotal1=throu1;
		sb_fprintf(stdout, "%g\tLatencia:%g\tThroughput:%g\t%s: Escritura del maestro Blocking \n",//para imprimirlas en pantalla jlpr
		sc_time_stamp().to_double(), latotal1, thtotal1, name());
	  
}
      if (status == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : blocking-write failed at address %x\n",
		   sc_time_stamp().to_double(), name(), m_address);

      wait(m_timeout, SC_NS);
    }
}
