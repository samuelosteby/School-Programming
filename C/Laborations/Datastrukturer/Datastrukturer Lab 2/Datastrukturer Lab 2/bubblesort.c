#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
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

void bubbleSort(int array[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}