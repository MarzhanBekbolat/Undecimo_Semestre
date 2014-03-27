#include "Testbenchalu.h"

Testbenchalu::Testbenchalu(sc_module_name nm) : sc_module(nm)
{
	SC_THREAD(test);
	sensitive << clk_in.pos();
	dont_initialize();
} 



void Testbenchalu::print() {
	cout << sc_time_stamp()
		 << "\t " << A.read()
		 << "\t " << B.read()
		 << "\t " << H.read()
		 << "\t " << C.read()
		 << "\t " << F3.read()
		 << "\t " << F2.read()
		 << "\t " << F1.read()
		 << "\t " << F0.read()		 
		 << "\t " << Y.read()
		 << endl;
}

void Testbenchalu::test()
{

	cout << "Time\t A\t\t B\t\t H\t\t C\t F3\t F2\t F1\t F0\t Y\t"<<endl;
	cout << "--------------------------------------------------------------------------------"<< endl;

	cout<< endl << "Escriba el nombre del archivo con la extension .txt:"<< endl; 

int n;
char x[100];

cin>>x;
n=strlen(x);
char archivo[n];
for(int j=0;j<n+1;j++)
{
	archivo[j]=x[j];
}

cout<<"El archivo es :"<<archivo<<endl;


FILE *f = fopen( archivo, "r");
if (f==NULL)
{
   perror ("Error al abrir archivo");
}

int Ain,Bin; 
for(int i=0;i<26;i++){
     fscanf (f, "%i", &Ain);
     fscanf (f, "_%i", &Bin);
  	cout << "Time\t A\t\t B\t\t H\t\t P\t\t C\t F3\t F2\t F1\t F0\t Y\t"<<endl;
	cout << "--------------------------------------------------------------------------------"<< endl;
	
	cout<<Ain<<endl;
	cout<<Bin<<endl;


sc_uint<8>  as;
sc_uint<8>  bs;
sc_uint<8>  cs;
sc_uint<8>  ds;

as=Ain;
bs=Bin;

if (as<bs){

cout <<"A tiene que ser mayor que B"<<endl;
sc_stop();
}	
else
{
as=Ain;
bs=Bin;

	A.write(Ain);
	B.write(Bin);
        H.write("00000000"); 	
 	P.write("00000000");	
	F4.write(0);
	F3.write(0);
        F2.write(1);
	F1.write(0);
	F0.write(1);
	

	wait();

	print();

cs=Y.read();


if (bs>cs) {
	A.write(A.read());
	B.write(B.read());
	H.write(Y.read());
	P.write(Y.read());	
	F4.write(1);
	F3.write(0);
        F2.write(0);
	F1.write(0);
	F0.write(1);
	

	wait();

	print();}

else      {
	A.write(A.read());
	B.write(B.read());
	H.write(Y.read());
	P.write(Y.read());
	F4.write(1);
	F3.write(0);
        F2.write(1);
	F1.write(0);
	F0.write(1);
	
	wait();

	print();	
	
}

	A.write(A.read());
	B.write(B.read());
	H.write(Y.read());
	P.write(Y.read());
	F4.write(0);
	F3.write(1);
        F2.write(0);
	F1.write(0);
	F0.write(0);	
	
	wait();

	print();	

}
 } 
fclose(f);	
sc_stop();
 
}
