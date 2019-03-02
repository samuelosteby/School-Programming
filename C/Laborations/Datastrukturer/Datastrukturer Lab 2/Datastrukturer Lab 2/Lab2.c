// Created by: Samuel Östeby
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"
#include "mergesort.h"

int main()
{
	printf("Exercise 1: \n\n");
	int testarray[] = { 9, 6, 0, 7, 1, 0, 0, 1, 3, 9 };
	int lab1list[] = { 3, 1, 5, 10, 8, 7 };
	int lab1list2[] = { 5, 2, 9, 6, 1, 2 };
	int length = sizeof(testarray) / sizeof(testarray[0]);
	int lengthlab1list = sizeof(lab1list) / sizeof(lab1list[0]);
	int lengthlab1list2 = sizeof(lab1list2) / sizeof(lab1list2[0]);

	printArray(lab1list, lengthlab1list);
	printf("Sorting with bubble sort...\n\n");
	bubbleSort(lab1list, lengthlab1list);
	printArray(lab1list, lengthlab1list);

	printArray(lab1list2, lengthlab1list2);
	printf("Sorting with bubble sort...\n\n");
	bubbleSort(lab1list2, lengthlab1list2);
	printArray(lab1list2, lengthlab1list2);

	printArray(testarray, length);
	printf("Sorting with bubble sort...\n\n");
	bubbleSort(testarray, length);
	printArray(testarray, length);
	
	printf("\n");

	printf("Exercise 2: \n\n");
	int testarray2[] = { 9, 6, 0, 7, 1, 0, 0, 1, 3, 9 };
	int lab1list_2[] = { 3, 1, 5, 10, 8, 7 };
	int lab1list2_2[] = { 5, 2, 9, 6, 1, 2 };
	int length2 = sizeof(testarray) / sizeof(testarray[0]);
	int lengthlab1list_2 = sizeof(lab1list) / sizeof(lab1list[0]);
	int lengthlab1list2_2 = sizeof(lab1list2) / sizeof(lab1list2[0]);

	printArray(lab1list_2, lengthlab1list_2);
	printf("Sorting with merge sort...\n\n");
	mergeSort(lab1list_2, 0, lengthlab1list_2 - 1);
	printArray(lab1list_2, sizeof(lab1list_2) / sizeof(lab1list_2[0]));

	printArray(lab1list2_2, lengthlab1list2_2);
	printf("Sorting with merge sort...\n\n");
	mergeSort(lab1list2_2, 0, lengthlab1list2_2 - 1);
	printArray(lab1list2_2, sizeof(lab1list2_2) / sizeof(lab1list2_2[0]));

	printArray(testarray2, length2);
	printf("Sorting with merge sort...\n\n");
	mergeSort(testarray2, 0, length2 - 1);
	printArray(testarray2, sizeof(testarray2) / sizeof(testarray2[0]));
	system("pause");
}