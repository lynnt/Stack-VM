CC=gcc #C compiler
CXX=g++ #C++ compiler
CFLAGS=-g -Wall -pedantic

OBJECT = vm.o
NAME = vm

all: $(OBJECT)
	$(CXX) $(CFLAGS) $(OBJECT) -o $(NAME)

run: vm
	./vm

clean:
	rm *.o
