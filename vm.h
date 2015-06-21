/*
 * vim: set ts=4, sts=4, sw=4
 * Copyright (c) 2015 Lynn Tran
 */

#ifndef VM_H
#define VM_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define STACK_SIZE 256

typedef enum{
    PUSH,
    ADD,
    POP,
    SET,
    HALT
} instructionSet;

typedef enum{
    A, B, C, D, E, F,
    NUM_REGISTERS
} Registers;

const int program[] = {
    PUSH, 5,
    PUSH, 6,
    ADD,
    POP,
    HALT
};

int registers[NUM_REGISTERS];
int programCounter = 0;
bool isRunning = 1;
int stackPointer = -1;
int stack[STACK_SIZE];

// Push instruction
void push();

// Halt instruction
void halt();

// Pop instruction
void pop();

// Add instruction
void add();

// Return the current instruction
int fetch(int programCounter);

// Evaluate instructions by checking each instruction and execute appropriately
void evaluate(int instruction);

// Virtualize program by evaluating and then incrementing the program counter to the next instruction
void virtualize();

#endif /*VM_H*/
