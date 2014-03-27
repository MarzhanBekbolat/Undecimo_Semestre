#ifndef __simple_bus_test_h
#define __simple_bus_test_h

#include <systemc.h>

#include "simple_bus_master_blocking.cpp"
#include "simple_bus_master_non_blocking.cpp"
#include "simple_bus_master_direct.cpp"
#include "simple_bus_slow_mem.h"
#include "simple_bus.cpp"
#include "simple_bus_fast_mem.h"
#include "simple_bus_arbiter.cpp"
#include "simple_bus_test.h"
#include "simple_bus_tools.cpp"
#include "simple_bus_types.cpp"

SC_MODULE(simple_bus_test)
{
  // channels
  sc_clock C1;

  // module instances
  simple_bus_master_blocking     *master_b;
  simple_bus_master_non_blocking *master_nb;
  simple_bus_master_blocking     *master_b1;
  simple_bus_master_non_blocking *master_nb1;
  simple_bus_master_direct       *master_d;
  simple_bus_slow_mem            *mem_slow;
  simple_bus                     *bus;
  simple_bus_fast_mem            *mem_fast;
  simple_bus_fast_mem            *mem_fasta;
  simple_bus_arbiter             *arbiter;

  // constructor
  SC_CTOR(simple_bus_test): C1("C1")
  {
    // create instances
    master_b = new simple_bus_master_blocking("master_1", 1, 0x70, true, 20);
    master_nb = new simple_bus_master_non_blocking("master_2", 2, 0x80, true, 15);
    master_b1 = new simple_bus_master_blocking("master_3", 3, 0x80, true, 10);
    master_nb1 = new simple_bus_master_non_blocking("master_4", 4, 0x70, true, 5);
    master_d = new simple_bus_master_direct("master_d", 0x70, 5);
    mem_fast = new simple_bus_fast_mem("mem_fast", 0x00, 0x47);
    mem_fasta = new simple_bus_fast_mem("mem_fasta", 0x48, 0x7f);
    mem_slow = new simple_bus_slow_mem("mem_slow", 0x80, 0xff, 5);
    bus = new simple_bus("bus",false); // verbose output
    //bus = new simple_bus("bus");
    arbiter = new simple_bus_arbiter("arbiter",false); // verbose output
    //arbiter = new simple_bus_arbiter("arbiter");

    // connect instances
    master_d->clock(C1);
    bus->clock(C1);
    master_b->clock(C1);
    master_nb->clock(C1);
    master_b1->clock(C1);
    master_nb1->clock(C1);
    mem_slow->clock(C1);
    master_d->bus_port(*bus);
    master_b->bus_port(*bus);
    master_nb->bus_port(*bus);
    master_b1->bus_port(*bus);
    master_nb1->bus_port(*bus);
    bus->arbiter_port(*arbiter);
    bus->slave_port(*mem_slow);
    bus->slave_port(*mem_fast);
    bus->slave_port(*mem_fasta);
  }

  // destructor
  ~simple_bus_test()
  {
    if (master_b) {delete master_b; master_b = 0;}
    if (master_nb) {delete master_nb; master_nb = 0;}
    if (master_b1) {delete master_b; master_b = 0;}
    if (master_nb1) {delete master_nb; master_nb = 0;}
    if (master_d) {delete master_d; master_d = 0;}
    if (mem_slow) {delete mem_slow; mem_slow = 0;}
    if (bus) {delete bus; bus = 0;}
    if (mem_fast) {delete mem_fast; mem_fast = 0;}
    if (mem_fasta) {delete mem_fasta; mem_fasta = 0;}
    if (arbiter) {delete arbiter; arbiter = 0;}
  }

}; // end class simple_bus_test

#endif
