#include <stdio.h>
#include <stdlib.h>
#include "stackarray.h"

Stack_array * getnewStack(Stack_array *Stack, int size)
{
	Stack = (Stack_array*)malloc(sizeof(Stack_array));
	Stack->size = size;
	Stack->data = (int*)malloc(sizeof(int) * Stack->size);
	Stack->tracker = -1;
	return Stack;
}

int pushStack(Stack_array *Stack, int data)
{
	if (Stack->tracker == -1) // Ensure stack is not marked as empty
	{
		Stack->tracker = 0;
		Stack->data[0] = data;
		printf("%d was added to stack!\n\n", data);
		printStack(Stack);
		return TRUE;
	}
	else if (Stack->tracker == Stack->size - 1) // If the stack is full
	{
		printf("Stack is full!\n\n");
		return FALSE;
	}
	else
	{
		Stack->tracker = Stack->tracker + 1;
		Stack->data[Stack->tracker] = data;
		printf("%d was added to stack!\n\n", data);

		printStack(Stack);
		return TRUE;
	}
}

int popStack(Stack_array *Stack)
{
	int result = 0, i = 0;

	if (Stack->tracker == -1) // If the stack is empty...
	{
		printf("Stack is empty!\n\n");
		return -999;
	}
	else
	{
		result = Stack->data[Stack->tracker];
		Stack->tracker = Stack->tracker - 1;
		printf("Returning %d\n\n", result);

		printStack(Stack);
		return result;
	}
}

void printStack(Stack_array *Stack)
{
	if (Stack->tracker == -1) // If the stack is empty...
	{
		printf("The stack is empty!\n\n");
	}
	else
	{
		printf("The stack: ");
		int i;
		for (i = 0; i <= Stack->tracker; i++)
		{
			printf("%d ", Stack->data[i]);
		}
		printf("\n\n");
	}
}