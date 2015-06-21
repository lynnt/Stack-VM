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
    int val = stack[stackPointer--];
    cout << "Popping value " << val << " ..." << endl;
}

void add(){
    int firstVal = stack[stackPointer--];
    int secondVal = stack[stackPointer--];
    stack[++stackPointer] = firstVal + secondVal;
    cout << "Adding " << firstVal << " + " << secondVal << " into " << stackPointer+1 << " ..." << endl;
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
