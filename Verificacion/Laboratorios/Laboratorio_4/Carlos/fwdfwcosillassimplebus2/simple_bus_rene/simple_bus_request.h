#ifndef __simple_bus_request_h
#define __simple_bus_request_h

enum simple_bus_lock_status { SIMPLE_BUS_LOCK_NO = 0
			      , SIMPLE_BUS_LOCK_SET
			      , SIMPLE_BUS_LOCK_GRANTED 
};

class simple_bus_request
{
	public:
  // parameters
  unsigned int priority;
  unsigned int order;

  // request parameters
  bool do_write;
  unsigned int address;
  unsigned int end_address;
  int *data;
  simple_bus_lock_status lock;

	//MY STATUS CHANGE
	void set_status(simple_bus_status state);
	simple_bus_status get_status();
	
  // request status
  sc_event transfer_done;
  
  // default constructor
  simple_bus_request();
  private:
  simple_bus_status status;
  double time;
};

inline void simple_bus_request::set_status(simple_bus_status state){
	static int total=0;
	static double n_proc=0;
	static double latency=0, max_lat=0, min_lat=99999, av_lat=0;
	static double throu=0;
	if(status==SIMPLE_BUS_REQUEST && (state==SIMPLE_BUS_OK || state==SIMPLE_BUS_WAIT)){
		sb_fprintf(stdout, " \t\t\t\t\t\t\t\t\t\t\t\t Starting Request %d @(%x,%x)\n",
						 priority,address,end_address);
		latency=(sc_time_stamp().to_double()-time)/1000;
		
		av_lat=(av_lat*total+latency)/(total+1);
		total++;
		if(latency>max_lat)max_lat=latency;
		if(latency<min_lat)min_lat=latency;
			
		sb_fprintf(stdout, "%g \tLATENCY (seconds): \t %g \n \t\t av : %g \n\t\t max : %g \n\t\t min : %g \n",
					 sc_time_stamp().to_double(),latency,av_lat,max_lat,min_lat);
	}
	else if(state==SIMPLE_BUS_REQUEST){
		sb_fprintf(stdout, "\t\t\t\t\t\t\t\t\t\t\t\t Asking for request %d \n", priority);
		time=sc_time_stamp().to_double();
	}
	if(state==SIMPLE_BUS_OK){
		sb_fprintf(stdout, "\t\t\t\t\t\t\t\t\t\t\t\t Finishing request %d @(%x)\n", priority,address);
		n_proc++;
		throu=1000*n_proc/sc_time_stamp().to_double();
		
		sb_fprintf(stdout, "%g \tTHROUGHPUT : \t %g \n\t\t-> %g requests in %g seconds \n\t\t-> %d ",
					 sc_time_stamp().to_double(),throu,n_proc,sc_time_stamp().to_double()/1000,priority,data,address);
		if(do_write)sb_fprintf(stdout, "writing %x in %x \n",*data,address);
		else sb_fprintf(stdout, "reading %x in %x \n",*data,address);
					 
	}

	status=state;
}
inline simple_bus_status simple_bus_request::get_status(){
	return status;
}

inline simple_bus_request::simple_bus_request()
  : priority(0)
  , order(0)
  , do_write(false)
  , address(0)
  , end_address(0)
  , data((int *)0)
  , lock(SIMPLE_BUS_LOCK_NO)
  , status(SIMPLE_BUS_OK)
{
	time=0;
}

#endif
