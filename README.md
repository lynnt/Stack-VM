A Stack based virtual machine
##HOW TO RUN
Currently the program array in vm.h is what will get run as a program
    ### TO BUILD:
    'make all'
    ### TO RUN:
    'make run'
    ### TO CLEAN:
    'make clean'

##DESIGN
* A set of registers
* A program to read in sequence of VM instructions
* An execution unit to run program

##INSTRUCTION SET

INSTRUCTION | OPERATION
------------| -------------
PUSH        |   Push value on the stack
ADD         |   Add 2 values together
MULTI       |   Multiply 2 values together
POP         |   Pop value off the stack
SET A 0     |   Set register value
HALT        |   Terminate the program


##IMPROVEMENT
    * Read in a file of program instead of the array in vm.h
    * Added more instructions
    * Added the decoding step where it uses addresses
