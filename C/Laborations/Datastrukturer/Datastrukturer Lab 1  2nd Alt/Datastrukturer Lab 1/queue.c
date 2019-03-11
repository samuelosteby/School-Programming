#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue * createQueue(Queue *Q, int size)
{
	Q = (Queue*)malloc(sizeof(Queue));
	Q->size = size;
	Q->head = -1;
	Q->rear = -1;
	Q->data = (int*)malloc(size * sizeof(int));
	return Q;
}

void printQueue(Queue *Q)
{
	if (Q == NULL)
	{
		printf("There is no queue.\n\n");
		return;
	}
	else if (Q->head == -1)
	{
		printf("The queue is empty.\n\n");
		return;
	}
	else
	{
		printf("The queue is: ");
		int i = 0;
		for (i = 0; i <= Q->rear; i++)
		{
			printf("%d ", Q->data[i]);
		}
		printf("\n\n");
		return;
	}
}

void enQueue(Queue *Q, int data)
{
	if (Q == NULL)
	{
		printf("There is no queue.\n\n");
		return;
	}
	else if (Q->rear == Q->size-1)
	{
		printf("The queue is full.\n\n");
		return;
	}
	else
	{
		if (Q->head == -1)
		{
			Q->head = 0;
		}
		Q->rear++;
		Q->data[Q->rear] = data;
		printQueue(Q);
		return;
	}
}

int deQueue(Queue *Q)
{
	if (Q == NULL)
	{
		printf("There is no queue.\n\n");
		return -1337;
	}
	else if (Q->head == -1)
	{
		printf("The queue is empty.\n\n");
		return -1337;
	}
	else
	{
		int i = 0;
		for (i = 0; i < Q->rear; i++)
		{
			Q->data[i] = Q->data[i + 1];
		}
		Q->rear--;

		printQueue(Q);
		return Q->data[0];
	}
}