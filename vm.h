#ifndef VM_H
#define VM_H

#define STACK_SIZE 256
#define MAX_TOKENS 100

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef enum{
    PUSH,
    ADD,
    MULTI,
    POP,
    SET,
    HALT,
    JZ
} instruction_set;

typedef enum{
    A, B, C, D, E, F,
    NUM_REGISTERS
} Registers;

#endif
