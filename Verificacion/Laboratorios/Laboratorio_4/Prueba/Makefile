# Simple Makefile for SystemC courses
# Universidad Nacional de Colombia, GMUN
# by Alejandro Duque, jaduquer@unal.edu.co

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


MODULE = simple_bus
SYSTEMC = /usr/local/systemc-2.3.0
LDFLAGS = -L$(SYSTEMC)/lib-linux -lsystemc
CXXFLAGS = -Wno-deprecated -I$(SYSTEMC)/include -fpermissive
 
all:
	g++ $(CXXFLAGS) -o $(MODULE) *.cpp $(LDFLAGS)
	./$(MODULE)
clean:
	rm -rf *o $(MODULE) *.vcd *.cpp~ *.h~ *~ output.csv
view: 
	$ gtkwave *.vcd
