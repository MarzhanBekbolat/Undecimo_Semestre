#-----------------------------------------------------------------------------------------
# Modelo de Makefile para compilaci�n de dise�os realizados con la librer�a SystemC
#----------------------------------------------------------------------------------------

# Especificar los archivos .cpp en SRCS y los archivos .h en SRCH
SRCS = TestAndGate.cpp AndGate.cpp Testbenchand.cpp

# Nombre del ejecutable 
TARGET = TestAndGate #OJO Son diferentes con TestAndGate.cpp

# Variable que apunta a la carpeta de SystemC
SYSTEMC = /opt/systemc-2.2.0

INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux
LIBS   = -lsystemc -lm

CC     = g++
CFLAGS = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)

#En caso de trabajar con windows colocar la extensi�n .exe
EXE    = $(TARGET)

.SUFFIXES: .cpp .o  

$(EXE): $(OBJS) $(SRCH)  
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

all: $(EXE)
	
.cpp.o:
	$(CC) $(DEBUG) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE) *.bak $(TARGET).stackdump *.vcd
