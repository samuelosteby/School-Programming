#pragma once
#define _merge_h
#define _mergesort_h

void merge(int array[], int low, int middle, int high); // Create temporary arrays, create merged sorted final array.

void mergeSort(int array[], int low, int high); // Initiate merge sort on array. Low = left index of array, high = right index of array