// Created by: Samuel Östeby
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"
#include "mergesort.h"
#include "integerarray.h"

int main()
{
	// EXERCISE 1
	printf("Exercise 1: \n\n");

	// Create arrays...
	Intarray * Iarraylab1 = NULL;
	Iarraylab1 = getnewIntarray(Iarraylab1, 6);
	Iarraylab1->data[0] = 3;
	Iarraylab1->data[1] = 1;
	Iarraylab1->data[2] = 5;
	Iarraylab1->data[3] = 10;
	Iarraylab1->data[4] = 8;
	Iarraylab1->data[5] = 7;

	Intarray * Iarraylab2 = NULL;
	Iarraylab2 = getnewIntarray(Iarraylab1, 6);
	Iarraylab2->data[0] = 5;
	Iarraylab2->data[1] = 2;
	Iarraylab2->data[2] = 9;
	Iarraylab2->data[3] = 6;
	Iarraylab2->data[4] = 1;
	Iarraylab2->data[5] = 2;

	Intarray * Iarray = NULL;
	Iarray = getnewIntarray(Iarray, 10);
	Iarray->data[0] = 9;
	Iarray->data[1] = 6;
	Iarray->data[2] = 0;
	Iarray->data[3] = 7;
	Iarray->data[4] = 1;
	Iarray->data[5] = 0;
	Iarray->data[6] = 0;
	Iarray->data[7] = 1;
	Iarray->data[8] = 3;
	Iarray->data[9] = 9;

	// Sort arrays...
	printArray(Iarraylab1->data, Iarraylab1->size);
	printf("Sorting with bubble sort...\n\n");
	bubbleSort(Iarraylab1->data, Iarraylab1->size);
	printArray(Iarraylab1->data, Iarraylab1->size);

	printArray(Iarraylab2->data, Iarraylab2->size);
	printf("Sorting with bubble sort...\n\n");
	bubbleSort(Iarraylab2->data, Iarraylab2->size);
	printArray(Iarraylab2->data, Iarraylab2->size);

	printArray(Iarray->data, Iarray->size);
	printf("Sorting with bubble sort...\n\n");
	bubbleSort(Iarray->data, Iarray->size);
	printArray(Iarray->data, Iarray->size);
	
	printf("\n");

	// Free memory of arrays
	free(Iarray);
	free(Iarraylab1);
	free(Iarraylab2);

	//EXERCISE 2
	printf("Exercise 2: \n\n");

	// Create arrays
	Iarraylab1 = getnewIntarray(Iarraylab1, 6);
	Iarraylab1->data[0] = 3;
	Iarraylab1->data[1] = 1;
	Iarraylab1->data[2] = 5;
	Iarraylab1->data[3] = 10;
	Iarraylab1->data[4] = 8;
	Iarraylab1->data[5] = 7;

	Iarraylab2 = getnewIntarray(Iarraylab1, 6);
	Iarraylab2->data[0] = 5;
	Iarraylab2->data[1] = 2;
	Iarraylab2->data[2] = 9;
	Iarraylab2->data[3] = 6;
	Iarraylab2->data[4] = 1;
	Iarraylab2->data[5] = 2;

	Iarray = getnewIntarray(Iarray, 10);
	Iarray->data[0] = 9;
	Iarray->data[1] = 6;
	Iarray->data[2] = 0;
	Iarray->data[3] = 7;
	Iarray->data[4] = 1;
	Iarray->data[5] = 0;
	Iarray->data[6] = 0;
	Iarray->data[7] = 1;
	Iarray->data[8] = 3;
	Iarray->data[9] = 9;

	// Sort arrays
	printArray(Iarraylab1->data, Iarraylab1->size);
	printf("Sorting with merge sort...\n\n");
	mergeSort(Iarraylab1->data, 0, Iarraylab1->size - 1);
	printArray(Iarraylab1->data, Iarraylab1->size);

	printArray(Iarraylab2->data, Iarraylab2->size);
	printf("Sorting with merge sort...\n\n");
	mergeSort(Iarraylab2->data, 0, Iarraylab2->size - 1);
	printArray(Iarraylab2->data, Iarraylab2->size);

	printArray(Iarray->data, Iarray->size);
	printf("Sorting with merge sort...\n\n");
	mergeSort(Iarray->data, 0, Iarray->size - 1);
	printArray(Iarray->data, Iarray->size);

	// Free memory of arrays
	free(Iarray);
	free(Iarraylab1);
	free(Iarraylab2);

	system("pause");
}