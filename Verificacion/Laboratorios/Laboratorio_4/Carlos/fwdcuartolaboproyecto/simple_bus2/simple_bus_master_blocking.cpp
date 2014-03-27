#include "simple_bus_master_blocking.h"

void simple_bus_master_blocking::main_action()
{
  const unsigned int mylength = 0x10; // storage capacity/burst length in words
  int mydata[mylength];
  unsigned int i;
  simple_bus_status status;
  //double count,tdume,tdumetot,tdumeblock, tdumeinir, tdumefinr, tdumer, tdumeiniw, tdumefinw, tdumew;

  while (true)
    {
      wait(); // ... for the next rising clock edge

      lat1 = sc_time_stamp().to_double();//convierte el tiempo sc_time_stamp() a double
      tdumeinir=sc_time_stamp().to_double();

      status = bus_port->burst_read(m_unique_priority, mydata, 
				    m_address, mylength, m_lock);
      if (status == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : blocking-read failed at address %x\n",
		   sc_time_stamp().to_double(), name(), m_address);

        tdumefinr=sc_time_stamp().to_double();
	tdumer=tdumefinr-tdumeinir;
	

      for (i = 0; i < mylength; ++i)
	{
	  mydata[i] += i;
	  wait();
	}

      lat1 = sc_time_stamp().to_double()-lat1;//se obtiene la latencia de cada maestro 
      tdumeiniw=sc_time_stamp().to_double();

      status = bus_port->burst_write(m_unique_priority, mydata, 
				     m_address, mylength, m_lock);


//para calcular las métricas:	  
	if (status == SIMPLE_BUS_OK){
	  	

	  	lat1 /= 1000;    //se debe al tiempo de simulacion del test
                laten1+=lat1;
		k1++;
		laten_total1=(laten1/k1)/5;

	  	thro1 = (32 * mylength)*1000/sc_time_stamp().to_double();
		throu1 += thro1;
		through_total1=throu1;
		sb_fprintf(stdout, "%g\tLatencia:%g\tThroughput:%g\t%s: Escritura del maestro Blocking \n",//para imprimirlas en pantalla
		sc_time_stamp().to_double(), laten_total1, through_total1, name());

                tdumefinw=sc_time_stamp().to_double();
	        tdumew=tdumefinw-tdumeiniw;
	       
	
         	count += 1;
	        tdume=tdumer+tdumew;
	        tdumetot += tdume;
	        tdumeblock=tdumetot/(2*count);
	        sb_fprintf(stdout, " \n contador: %g \t tdume: %g \t tdume total: %g \t tdume blocking: %g \n",count,tdume,tdumetot,tdumeblock);


	  
}

      if (status == SIMPLE_BUS_ERROR)
	sb_fprintf(stdout, "%g %s : blocking-write failed at address %x\n",
		   sc_time_stamp().to_double(), name(), m_address);

      wait(m_timeout, SC_NS);
    }
}
