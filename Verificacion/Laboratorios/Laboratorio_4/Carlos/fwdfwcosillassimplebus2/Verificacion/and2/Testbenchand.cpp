# include "Testbenchand.h"

Testbenchand::Testbenchand(sc_module_name nm) : sc_module(nm)
{
	SC_THREAD(test);
	sensitive << clk_in.pos();
	dont_initialize();
}

void Testbenchand::print() {
	cout << sc_time_stamp()
		 << "\t " << A.read()
		 << "\t " << B.read()
		 << "\t " << Y.read()
		 << endl;
}

void Testbenchand::test()
{
	cout << "Time\t A\t\t B\t\t\t Y"<<endl;
	cout<< "--------------------------------------------"<<endl;
		

	A.write(00000000);
	B.write(00000000);

	wait();

	print();

	A.write(10000000);
	B.write(00000000);

	wait();

	print();

	A.write(00000000);
	B.write(10000000);

	wait();

	print();

	A.write(10000001);
	B.write(10000010);

	wait();

	print();

	sc_stop();
}

