#pragma once
#define _getNewArray_h
#define _printArray_h
#define _sortArray_h

typedef struct Intarray // Data type for integer arrays
{
	int size;
	int *data;
}Intarray;

Intarray * getNewIntarray(Intarray *Iarray, int size); // Create new integer array of given size

void printArray(Intarray *Array); // Prints out an array of a given size

void sortArray(Intarray *Array); // Prints an array in sorted order by creating a binary tree, traversing it inorder and then printing the nodes passed