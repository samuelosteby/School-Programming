#include <stdio.h>
#include <stdlib.h>
#include "stackarray.h"

StackArray * createStack(StackArray *Stack, int size)
{
	// Allocate memory for, create and return Stack
	Stack = (StackArray*)malloc(sizeof(Stack));
	Stack->size = size;
	Stack->data = (int*)malloc((size) * sizeof(int));
	Stack->head = -1;
	return Stack;
}

void printStack(StackArray *Stack)
{
	if (Stack == NULL) // If the Stack doesn't exist...
	{
		printf("There is no Stack. \n\n");
		return;
	}
	else if (Stack->head == -1) // If the Stack is empty...
	{
		printf("The Stack is empty.\n\n");
		return;
	}
	else
	{
		int i = 0;
		printf("The Stack is: ");
		for (i = 0; i <= Stack->head; i++) // Go through filled parts of Stack
		{
			printf("%d ", Stack->data[i]);
		}
		printf("\n\n");
		return;
	}
}

int pop(StackArray *Stack)
{
	if (Stack == NULL)
	{
		printf("There is no Stack. \n\n"); // If the Stack doesn't exist...
		return -99999;
	}
	else if (Stack->head == -1) // If the Stack is empty...
	{
		printf("The Stack is empty.\n\n");
		return -99999;
	}
	else
	{
		Stack->head--;
		printStack(Stack);
		return Stack->data[Stack->head + 1];
	}
}

void push(StackArray *Stack, int data)
{
	if (Stack == NULL)
	{
		printf("There is no Stack. \n\n");
		return;
	}
	else if (Stack->head == Stack->size - 1)
	{
		printf("The Stack is full. \n\n");
		return;
	}
	else
	{
		Stack->head++;
		Stack->data[Stack->head] = data;
		printStack(Stack);
		return;
	}
}

