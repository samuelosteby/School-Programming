#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(int array[], int low, int mid, int high)
{
	int i, j, k;
	int fhstart = mid - low + 1;
	int shstart = high - mid;

	int *fharray = malloc(fhstart * sizeof(*fharray));
	int *sharray = malloc(shstart * sizeof(*fharray));

	for (i = 0; i < fhstart; i++)
	{
		fharray[i] = array[low + i];
	}
	for (j = 0; j < shstart; j++)
	{
		sharray[j] = array[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = low;

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

	while (i < fhstart)
	{
		array[k] = fharray[i];
		i++;
		k++;
	}

	while (j < shstart)
	{
		array[k] = sharray[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;

		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}