#include <stdio.h>
#include <stdlib.h>
#include "integerarray.h"

Intarray * getnewIntarray(Intarray *Iarray, int size)
{
	Iarray = (Intarray*)malloc(sizeof(Intarray));
	Iarray->size = size;
	Iarray->data = (int*)malloc(sizeof(int) * Iarray->size);
	return Iarray;
}

void printArray(int array[], int size)
{
	int i;
	printf("The array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}