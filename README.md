A Stack based virtual machine
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
