
#CC = aarch64-linux-gnu-c++
#CFLAGS = #-O2
#
#-------enable gdb
#DBUG = -g
#------head file path
#INCLUDE = -I../out/include/ -I../out/include/alize-core/include/ -I../dao/ -I../model -I../utils -I.
#
#-----Shared library
#LIBS = -lpthread -lsqlite3 -lcgic
#
#-----Shared library path
#LD_FLAG = -L../out/lib
#
#----used for net programing
#CGIS = $(patsubst %cpp, %cgi, $(SRCS))  
#
#----deep objects
#DEP_OBJS = ../dao/sysUserDml.o \
            ../dao/userEnrollDml.o \
            ../logApi/log.o \
            ../utils/util.o \
            ../model/userEnroll.o

CXX = g++ 
STDFLAGS = c++17
BIN = Employee_system
SRCS = $(wildcard *.cpp)  
OBJS = $(patsubst %cpp, %o, $(SRCS))

.PHONY : clean
all:$(BIN)

clean:
	rm -f $(OBJS) $(BIN)

$(BIN) : $(OBJS)
	$(CXX) -std=$(STDFLAGS) -o $@ $ *.o 

$(OBJS) : %.o : %.cpp 
	$(CXX) -c -std=$(STDFLAGS) $<
