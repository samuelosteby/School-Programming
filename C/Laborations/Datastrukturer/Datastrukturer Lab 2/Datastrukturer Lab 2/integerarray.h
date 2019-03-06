#pragma once
#define _getnewIntarray_h
#define _printArray_h

typedef struct Intarray // Data type for integer arrays
{
	int size;
	int *data;
	int front;
	int rear;
}Intarray;

Intarray * getnewIntarray(Intarray *Iarray, int size); // Create new integer array of given size

void printArray(int array[], int size); // Prints out an array of a given size