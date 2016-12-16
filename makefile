CC=gcc #C compiler
CXX=g++ #C++ compiler
CFLAGS=-g -Wall -pedantic

OBJECT = vm.o
FILE = vm.c

all: $(OBJECT)
	$(CC) $(CFLAGS) $(FILE) -o $(OBJECT)

run: vm
	./vm

clean:
	rm *.o
