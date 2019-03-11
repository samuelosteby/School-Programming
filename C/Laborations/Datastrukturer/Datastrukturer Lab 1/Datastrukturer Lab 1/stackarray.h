#pragma once

#define _createStack_h
#define _printStack_h
#define _pop_h
#define _push_h


typedef struct StackArray
{
	int head;
	int size;
	int *data;

}StackArray;

StackArray * createStack(StackArray *Stack, int size); // Creates stack with given size and returns it

void printStack(StackArray *Stack); // Prints all elements in stack

int pop(StackArray *Stack); // Returns top of stack, otherwise returns -99999

void push(StackArray *Stack, int data); // Adds data to top of stack