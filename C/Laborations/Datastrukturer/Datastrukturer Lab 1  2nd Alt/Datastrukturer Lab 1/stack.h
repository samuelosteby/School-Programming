#pragma once

#define _createStack_h
#define _printStack_h
#define _pop_h
#define _push_h


typedef struct Stack
{
	int head;
	int size;
	int *data;

}Stack;

Stack * createStack(Stack *S, int size); //Creates stack with input size and returns it.

void printStack(Stack *S); //Prints all elements in stack.

int pop(Stack *S); //Reads from top of stack. Returns -1337 if empty otherwise it returns top of stack.

void push(Stack *S, int data); //Adds data to top of stack.

