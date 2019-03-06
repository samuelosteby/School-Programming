#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(int array[], int low, int mid, int high) // Merges two subarrays
{
	// Initialize variables and find first and second half of array (low to mid & mid + 1 to high)
	int i, j, k;
	int fhstart = mid - low + 1;
	int shstart = high - mid;

	// Allocate memory for temporary arrays
	int *fharray = malloc(fhstart * sizeof(*fharray));
	int *sharray = malloc(shstart * sizeof(*fharray));

	// Copy data from the entered array into temporary arrays
	for (i = 0; i < fhstart; i++)
	{
		fharray[i] = array[low + i];
	}
	for (j = 0; j < shstart; j++)
	{
		sharray[j] = array[mid + 1 + j];
	}

	// Re-initialize indexes
	i = 0; // Index of first half
	j = 0; // Index of second half
	k = low; // Index of merged array

	// Sort through temporary arrays and determine position on final array
	while (i < fhstart && j < shstart)
	{
		if (fharray[i] <= sharray[j])
		{
			array[k] = fharray[i];
			i++;
		}
		else
		{
			array[k] = sharray[j];
			j++;
		}
		k++;
	}

	// Copy remains from first temporary array to final array
	while (i < fhstart)
	{
		array[k] = fharray[i];
		i++;
		k++;
	}

	// Copy remains from second temporary array to final array
	while (j < shstart)
	{
		array[k] = sharray[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int low, int high)
{
	if (low < high) // Check to ensure no overflow
	{
		int mid = low + (high - low) / 2; // Find middle of array and save it into variable

		mergeSort(array, low, mid); // Sort lower half of array recursively
		mergeSort(array, mid + 1, high); // Sort higher half of array recursively
		merge(array, low, mid, high); // Merge sorted arrays
	}
}