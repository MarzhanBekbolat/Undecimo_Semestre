#include "systemc.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "stdlib.h"
using namespace std;

SC_MODULE(output){
	sc_in<sc_bv<8> > in1 , in2, out1;
   sc_int<50> in1_int, in2_int, out1_int;
   void do_out(){
      int i=0;
      in1_int=in1.read();
		in2_int=in2.read();
		out1_int=out1.read();
      ofstream outFile ("output.csv");
      //outFile << "Wind Farm Data, Wind Speed, Power Generated" << endl;
      while(i<50){
      outFile << in1_int << ',' << in2_int << ',' << out1_int << endl;
  
      i=i+1;   
      }
   outFile.close();
   }

SC_CTOR(output){
		SC_METHOD(do_out);
		sensitive <<in1<<in2<<out1;
	}
};
