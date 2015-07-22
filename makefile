CC=gcc #C compiler
CXX=g++ #C++ compiler
CFLAGS=-g -Wall -pedantic

OBJECT = vm.o

all: $(OBJECT)
	$(CXX) $(CFLAGS) $(OBJECT) -o vm

run: vm
	./vm

clean:
	rm *.o
