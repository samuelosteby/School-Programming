#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * createStack(Stack *S, int size)
{
	S = (Stack*)malloc(sizeof(Stack));
	S->size = size;
	S->data = (int*)malloc((size) * sizeof(int));
	S->head = -1;
	return S;
}

void printStack(Stack *S)
{
	if (S == NULL)
	{
		printf("There is no stack. \n\n");
		return;
	}
	else if (S->head == -1)
	{
		printf("The stack is empty.\n\n");
		return;
	}
	else
	{
		int i = 0;
		printf("The stack is: ");
		for (i = 0; i <= S->head; i++)
		{
			printf("%d ", S->data[i]);
		}
		printf("\n\n");
		return;
	}
}

int pop(Stack *S)
{
	if (S == NULL)
	{
		printf("There is no stack. \n\n");
		return -1337;
	}
	else if (S->head == -1)
	{
		printf("The stack is empty.\n\n");
		return -1337;
	}
	else
	{
		S->head--;
		printStack(S);
		return S->data[S->head + 1];
	}
}

void push(Stack *S, int data)
{
	if (S == NULL)
	{
		printf("There is no stack. \n\n");
		return;
	}
	else if(S->head == S->size - 1)
	{
		printf("The stack is full. \n\n");
		return;
	}
	else
	{
		S->head++;
		S->data[S->head] = data;
		printStack(S);
		return;
	}
}

