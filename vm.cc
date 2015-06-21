/*
 * vim: set ts=4, sts=4, sw=4
 * Copyright (c) 2015 Lynn Tran
 */

#include"vm.h"
using namespace std;

void push(){
    stackPointer++;
    stack[stackPointer] = program[++programCounter];
    cout << "Pushing value " << program[programCounter] << "..." << endl;
}

void halt(){
    isRunning = 0;
    cout << "Halting ... " << endl;
}

void pop(){
    assert(stackPointer > -1);
    int val = stack[stackPointer--];
    cout << "Popping value " << val << " ..." << endl;
}

void add(){
    assert(stackPointer > -1);
    int firstVal = stack[stackPointer--];
    int secondVal = stack[stackPointer--];
    stack[++stackPointer] = firstVal + secondVal;
    cout << "Adding " << firstVal << " + " << secondVal << " into " << stackPointer << " ..." << endl;
}

void multi(){
    assert(stackPointer > -1);
    int firstVal = stack[stackPointer--];
    int secondVal = stack[stackPointer--];
    stack[++stackPointer] = firstVal * secondVal;
    cout << "Multiplying " << firstVal << " * " << secondVal << " into " << stackPointer << " ..." << endl;
}

void jz(int index){
    assert(stackPointer > -1);
    if(stackPointer == 0){
        stackPointer--;
        programCounter = index;
    }
    else if(stackPointer > 0){
        stackPointer--;
    }
}

int fetch(int programCounter){
    return program[programCounter];
}

int evaluate(int instruction){
    switch(instruction){
        case HALT: {
                       halt();
                       break;
                   }
        case PUSH: {
                       push();
                       break;
                   }
        case POP: {
                      pop();
                      break;
                  }
        case ADD: {
                      add();
                      break;
                  }
        case MULTI: {
                      multi();
                      break;
                    }
        default:
                    cerr << "This instruction isn't supported" << endl;
                    return -1;
    }
}

void virtualize(){
    while(isRunning){
        evaluate(fetch(programCounter));
        programCounter++;
    }
}

int openFile(ifstream& input, char* filename){
    input.open(filename);
    if(!input.is_open()){
        cerr << "Can't open file." << endl;
        return -1;
    }
}

void closeFile(ifstream& input){
    input.close();
}

int main(){
    virtualize();
}
