#include <stdio.h>
#include <stdlib.h>
#include "integerarray.h"
#include "binarytree.h"

Intarray * getNewIntarray(Intarray *Iarray, int size)
{
	// Allocate and create an integer array struct of a given size
	Iarray = (Intarray*)malloc(sizeof(Intarray));
	Iarray->size = size;
	Iarray->data = (int*)malloc(sizeof(int) * Iarray->size);
	return Iarray;
}

void printArray(Intarray *Array)
{
	// Loop through the array's data and print it
	int i;
	printf("The array: ");
	for (i = 0; i < Array->size; i++)
	{
		printf("%d ", Array->data[i]);
	}
	printf("\n\n");
}

void sortArray(Intarray *Array)
{

	// Create temporary binary tree
	TreeNode * Root = NULL;
	TreeNode * Temp = NULL;

	// Create root to binary tree
	Root = getNewRoot(Root, Array->data[0]);

	// Populate tree with nodes based on the array
	for (int i = 1; i < Array->size; i++)
	{
		Temp = getNewTreeNode(Temp, Array->data[i]);
		insert(Root, Temp);
	}

	// Travese the tree inorder / sorted order and print the nodes passed
	printf("Sorted array: ");
	traverseTreeInOrder(Root);
	printf("\n\n");

	// Free memory allocated to temporary binary tree
	freeTree(Root);

	return;
}