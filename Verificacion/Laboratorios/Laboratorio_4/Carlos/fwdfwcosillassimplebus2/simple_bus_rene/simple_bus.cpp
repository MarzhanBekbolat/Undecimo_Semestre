#include "simple_bus.h"

void simple_bus::end_of_elaboration()
{
  // perform a static check for overlapping memory areas of the slaves
  bool no_overlap;
  for (int i = 1; i < slave_port.size(); ++i) {
    simple_bus_slave_if *slave1 = slave_port[i];
    for (int j = 0; j < i; ++j) {
      simple_bus_slave_if *slave2 = slave_port[j]; 
      no_overlap = ( slave1->end_address() < slave2->start_address() ) ||
               ( slave1->start_address() > slave2->end_address() );
      if ( !no_overlap ) {
        sb_fprintf(stdout,"Error: overlapping address spaces of 2 slaves : \n");
        sb_fprintf(stdout,"slave %i : %0X..%0X\n",i,slave1->start_address(),slave1->end_address()); 
        sb_fprintf(stdout,"slave %i : %0X..%0X\n",j,slave2->start_address(),slave2->end_address());
        exit(0);
      }
    }
  }
}

//----------------------------------------------------------------------------
//-- process
//----------------------------------------------------------------------------

void simple_bus::main_action()
{
  // m_current_request is cleared after the slave is done with a
  // single data transfer. Burst requests require the arbiter to
  // select the request again.
  if (!m_current_request){
	m_current_request = get_next_request();
  }
  else
    // monitor slave wait states
  if (m_verbose)
      sb_fprintf(stdout, "%g SLV [%x]\n", sc_time_stamp().to_double(),m_current_request->address);
  if (m_current_request){
    handle_request();
    used+=1;
    total+=1;
  }else {
    	total+=1;
  }
  if (!m_current_request){
    clear_locks();
  }
  bus_use=(100*used)/total;
  sb_fprintf(stdout, "%g used: %f %\n", sc_time_stamp().to_double(),bus_use);
}

//----------------------------------------------------------------------------
//-- direct BUS interface
//----------------------------------------------------------------------------

bool simple_bus::direct_read(int *data, unsigned int address)
{
  if (address%4 != 0 ) {// address not word alligned
    sb_fprintf(stdout, "  BUS ERROR --> address %04X not word alligned\n",address);
    return false; 
  }
  simple_bus_slave_if *slave = get_slave(address);
  if (!slave) return false;
  return slave->direct_read(data, address);
}

bool simple_bus::direct_write(int *data, unsigned int address)
{
  if (address%4 != 0 ) {// address not word alligned
    sb_fprintf(stdout, "  BUS ERROR --> address %04X not word alligned\n",address);
    return false; 
  }
  simple_bus_slave_if *slave = get_slave(address);
  if (!slave) return false;
  return slave->direct_write(data, address);
}

//----------------------------------------------------------------------------
//-- non-blocking BUS interface
//----------------------------------------------------------------------------

void simple_bus::read(unsigned int unique_priority
		      , int *data
		      , unsigned int address
		      , bool lock)
{
  if (m_verbose)
    sb_fprintf(stdout, "%g %s : read(%d) @ %x\n",
	       sc_time_stamp().to_double(), name(), unique_priority, address);
  
  simple_bus_request *request = get_request(unique_priority);

  // abort when the request is still not finished
  sc_assert((request->get_status() == SIMPLE_BUS_OK) ||
	    (request->get_status() == SIMPLE_BUS_ERROR));

  request->do_write           = false; // we are reading
  request->address            = address;
  request->end_address        = address;
  request->data               = data;
  unsigned int ord=0;
  for (int i = 0; i < m_requests.size(); ++i)
		if(m_requests[i]->order>ord && m_requests[i]->order<5)ord=m_requests[i]->order;
  request->order 					= ++ord;

  if (lock)
    request->lock = (request->lock == SIMPLE_BUS_LOCK_SET) ? 
      SIMPLE_BUS_LOCK_GRANTED : SIMPLE_BUS_LOCK_SET;

  request->set_status(SIMPLE_BUS_REQUEST);
}

void simple_bus::write(unsigned int unique_priority
		       , int *data
		       , unsigned int address
		       , bool lock)
{
  if (m_verbose) 
    sb_fprintf(stdout, "%g %s : write(%d) @ %x\n",
	       sc_time_stamp().to_double(), name(), unique_priority, address);

  simple_bus_request *request = get_request(unique_priority);

  // abort when the request is still not finished
  sc_assert((request->get_status() == SIMPLE_BUS_OK) ||
	    (request->get_status() == SIMPLE_BUS_ERROR));

  request->do_write           = true; // we are writing
  request->address            = address;
  request->end_address        = address;
  request->data               = data;
  unsigned int ord=0;
  for (int i = 0; i < m_requests.size(); ++i)
		if(m_requests[i]->order>ord && m_requests[i]->order<5)ord=m_requests[i]->order;
  request->order 					= ++ord;

  if (lock)
    request->lock = (request->lock == SIMPLE_BUS_LOCK_SET) ?
      SIMPLE_BUS_LOCK_GRANTED : SIMPLE_BUS_LOCK_SET;

  request->set_status(SIMPLE_BUS_REQUEST);
}

simple_bus_status simple_bus::get_status(unsigned int unique_priority)
{
  return get_request(unique_priority)->get_status();
}

//----------------------------------------------------------------------------
//-- blocking BUS interface
//----------------------------------------------------------------------------

simple_bus_status simple_bus::burst_read(unsigned int unique_priority
					 , int *data
					 , unsigned int start_address
					 , unsigned int length
					 , bool lock)
{
  if (m_verbose) 
  {
    sb_fprintf(stdout, "%g %s : burst_read(%d) @ %x\n",
	sc_time_stamp().to_double(), name(), unique_priority, 
	start_address);
  }
	
  simple_bus_request *request = get_request(unique_priority);

  request->do_write           = false; // we are reading
  request->address            = start_address;
  request->end_address        = start_address + (length-1)*4;
  request->data               = data;
  unsigned int ord=0;
  for (int i = 0; i < m_requests.size(); ++i)
		if(m_requests[i]->order>ord && m_requests[i]->order<5)ord=m_requests[i]->order;
  request->order 					= ++ord;

  if (lock)
    request->lock = (request->lock == SIMPLE_BUS_LOCK_SET) ? 
      SIMPLE_BUS_LOCK_GRANTED : SIMPLE_BUS_LOCK_SET;

  request->set_status(SIMPLE_BUS_REQUEST);

  wait(request->transfer_done);
  wait(clock->posedge_event());
  return request->get_status();
}

simple_bus_status simple_bus::burst_write(unsigned int unique_priority
					  , int *data
					  , unsigned int start_address
					  , unsigned int length
					  , bool lock)
{
  if (m_verbose) 
    sb_fprintf(stdout, "%g %s : burst_write(%d) @ %x\n",
	       sc_time_stamp().to_double(), name(), unique_priority, 
	       start_address);
	
  simple_bus_request *request = get_request(unique_priority);

  request->do_write           = true; // we are writing
  request->address            = start_address;
  request->end_address        = start_address + (length-1)*4;
  request->data               = data;
  unsigned int ord=0;
  for (int i = 0; i < m_requests.size(); ++i)
		if(m_requests[i]->order>ord && m_requests[i]->order<5)ord=m_requests[i]->order;
  request->order 					= ++ord;

  if (lock)
    request->lock = (request->lock == SIMPLE_BUS_LOCK_SET) ? 
      SIMPLE_BUS_LOCK_GRANTED : SIMPLE_BUS_LOCK_SET;

  request->set_status(SIMPLE_BUS_REQUEST);

  wait(request->transfer_done);
  wait(clock->posedge_event());
  return request->get_status();
}

//----------------------------------------------------------------------------
//-- BUS methods:
//
//     handle_request()   : performs atomic bus-to-slave request
//     get_request()      : BUS-interface: gets the request form of given 
//                          priority
//     get_next_request() : returns a valid request out of the list of 
//                          pending requests
//     clear_locks()      : downgrade the lock status of the requests once
//                          the transfer is done
//----------------------------------------------------------------------------

void simple_bus::handle_request()
{
  if (m_verbose)
      sb_fprintf(stdout, "%g %s Handle Slave(%d)\n",
		 sc_time_stamp().to_double(), name(), 
		 m_current_request->priority);

  m_current_request->set_status(SIMPLE_BUS_WAIT);
  simple_bus_slave_if *slave = get_slave(m_current_request->address);
        
  if ((m_current_request->address)%4 != 0 ) {// address not word alligned
    sb_fprintf(stdout, "  BUS ERROR --> address %04X not word alligned\n",m_current_request->address);
    m_current_request->set_status(SIMPLE_BUS_ERROR);
    m_current_request = (simple_bus_request *)0;
    return;
  }
  if (!slave) {
    sb_fprintf(stdout, "  BUS ERROR --> no slave for address %04X \n",m_current_request->address);
    m_current_request->set_status(SIMPLE_BUS_ERROR);
    m_current_request = (simple_bus_request *)0;
    return;
  }

  simple_bus_status slave_status = SIMPLE_BUS_OK;
  if (m_current_request->do_write)
    slave_status = slave->write(m_current_request->data, 
				m_current_request->address);
  else
    slave_status = slave->read(m_current_request->data,
			       m_current_request->address);

  if (m_verbose)
    sb_fprintf(stdout, "  --> status=(%s)\n", simple_bus_status_str[slave_status]);

int size=m_requests.size();
  switch(slave_status)
    {
    case SIMPLE_BUS_ERROR:
		for (int i = 0; i < size; ++i) {
			if(m_requests[i]->order==1)m_requests[i]->order=size+10;
			else m_requests[i]->order--;
			
			//sb_fprintf(stdout, "\t\t\t\t\t\t\t\t\t\t  --> listing=(%d %d)\n", m_requests[i]->priority,m_requests[i]->order);
		}
			
      m_current_request->set_status(SIMPLE_BUS_ERROR);
      m_current_request->transfer_done.notify();
      m_current_request = (simple_bus_request *)0;
      break;
    case SIMPLE_BUS_OK:
  		m_current_request->set_status(SIMPLE_BUS_OK);
      m_current_request->address+=4; //next word (byte addressing)
      m_current_request->data++;
      if (m_current_request->address > m_current_request->end_address)
	{
		// burst-transfer (or single transfer) completed
	  //m_current_request->set_status(SIMPLE_BUS_OK);
		for (int i = 0; i < size; ++i) {
			if(m_requests[i]->order==1)m_requests[i]->order=size+10;
			else m_requests[i]->order--;
			
			//sb_fprintf(stdout, "\t\t\t\t\t\t\t\t\t\t  --> listing=(%d %d)\n",
			//						 m_requests[i]->priority,m_requests[i]->order);
		}
		
		m_current_request->transfer_done.notify();
		m_current_request = (simple_bus_request *)0;
	}
      else
	{ // more data to transfer, but the (atomic) slave transfer is done
		m_current_request->set_status(SIMPLE_BUS_WAIT);
	  	m_current_request = (simple_bus_request *)0;
	  
	}
      break;
    case SIMPLE_BUS_WAIT:
      // the slave is still processing: no clearance of the current request
      break;
    default:
      break;
    }
}

simple_bus_slave_if *simple_bus::get_slave(unsigned int address)
{
  for (int i = 0; i < slave_port.size(); ++i)
    {
      simple_bus_slave_if *slave = slave_port[i];
      if ((slave->start_address() <= address) &&
	  (address <= slave->end_address()))
	return slave;
    }
  return (simple_bus_slave_if *)0;		
}

simple_bus_request * simple_bus::get_request(unsigned int priority)
{
  simple_bus_request *request = (simple_bus_request *)0;
  //mira si ya se genero el request con esta prioridad, si si se genero ya se devuelve, si no se crea dicho request
  for (int i = 0; i < m_requests.size(); ++i)
    {
      request = m_requests[i];
      if ((request) && (request->priority == priority)){
			return request;
		}
    }
  request = new simple_bus_request;
  request->priority = priority;
  m_requests.push_back(request);
  return request;		
}

simple_bus_request * simple_bus::get_next_request()
{
  // the slave is done with its action, m_current_request is
  // empty, so go over the bag of request-forms and compose
  // a set of likely requests. Pass it to the arbiter for the
  // final selection
  simple_bus_request_vec Q;
  for (int i = 0; i < m_requests.size(); ++i)
    {
      simple_bus_request *request = m_requests[i];
      if ((request->get_status() == SIMPLE_BUS_REQUEST) ||
	  (request->get_status() == SIMPLE_BUS_WAIT))
	{
	  if (m_verbose) 
	    sb_fprintf(stdout, "%g %s : request (%d) [%s]\n",
		       sc_time_stamp().to_double(), name(), 
		       request->priority, simple_bus_status_str[request->get_status()]);
	  Q.push_back(	request);
	}
    }
  if (Q.size() > 0)
    return arbiter_port->arbitrate(Q);
  return (simple_bus_request *)0;
}

void simple_bus::clear_locks()
{
  for (int i = 0; i < m_requests.size(); ++i)
    if (m_requests[i]->lock == SIMPLE_BUS_LOCK_GRANTED)
      m_requests[i]->lock = SIMPLE_BUS_LOCK_SET;
    else
      m_requests[i]->lock = SIMPLE_BUS_LOCK_NO;
}
