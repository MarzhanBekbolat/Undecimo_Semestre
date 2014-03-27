#include "systemc.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "stdlib.h"
using namespace std;

SC_MODULE(stim){
	sc_in<bool> Clk;
	sc_out<sc_bv<8> > A, B;
    sc_out<bool> C;
	sc_out<sc_bv<2> > F;
	sc_in < sc_bv<8> > sal;
	const int ROWS = 200;
	const int COLS = 2;
	const int BUFFSIZE = 80;
	void gen(){
		int array[ROWS][COLS];
		char buff[BUFFSIZE];
		ifstream file( "in.csv" );
		ofstream w( "out.csv" );

		w<< "Simulando el datapath "<<endl<<endl<<endl;
		w<<"Dato1"<<','<<"Dato2"<<','<<"F2"<<','<<"F1:0"<<','<<"Resultado"<<endl;

		string line; 
		int col = 0;
		int row = 0;
		int in1, in2, sal1;
		
		wait();
		while( getline( file, line ) ){
			istringstream iss( line );
			string result;
			while( getline( iss, result, ',' ) ){
				wait();			
				if (col == 0){
					array[row][col] = atoi( result.c_str() );						
					in1 = atoi( result.c_str() );					
				}
				else {
					array[row][col] = atoi( result.c_str() );
					in2 = atoi( result.c_str() );
				}
				col = col+1;
	C.write(false);//true resta false suma
	F.write(0b10);
			}
	A=in1;
	B=in2;
	row = row+1;
	col = 0;
	wait();
	sal1=sal.read().to_uint();
	w << in1 << ',' << in2 << ',' <<C<<','<<F<<','<<sal1<<endl;

		}
	w.close();
	sc_stop();
	}
	SC_CTOR(stim){
		SC_THREAD(gen);
		sensitive << Clk.pos();
	}
};
