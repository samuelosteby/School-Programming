#pragma once
#define _getnewStack_h
#define _pushStack_h
#define _popStack_h
#define _printStack_h
#define TRUE 1
#define FALSE 0

typedef struct Stack_array // Node to be used in linked list
{
	int size;
	int *data;
	int tracker;
}Stack_array;

Stack_array * getnewStack(Stack_array *Stack, int size); // Creates new Queue

int pushStack(Stack_array *Stack, int data); // Adds data to end to queue. Returns TRUE if successful, FALSE if unsuccessful

int popStack(Stack_array *Stack); // Reads data from start of queue and returns it, returns -999 if queue is empty

void printStack(Stack_array *Stack); // Prints out all the values in the stack