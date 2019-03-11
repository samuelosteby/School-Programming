#include <stdio.h>
#include <stdlib.h>
#include "queuearray.h"

QueueArray * createQueue(QueueArray *Queue, int size)
{
	Queue = (QueueArray*)malloc(sizeof(Queue));
	Queue->size = size;
	Queue->front = -1;
	Queue->rear = -1;
	Queue->data = (int*)malloc(size * sizeof(int));
	return Queue;
}

void printQueue(QueueArray *Queue)
{
	if (Queue == NULL)
	{
		printf("There is no Queue.\n\n"); // If the Queue doesn't exist...
		return;
	}
	else if (Queue->front == -1) // If the Queue is empty...
	{
		printf("The Queue is empty.\n\n");
		return;
	}
	else
	{
		printf("The Queue is: ");
		int i = 0;
		for (i = 0; i <= Queue->rear; i++)
		{
			printf("%d ", Queue->data[i]);
		}
		printf("\n\n");
		return;
	}
}

void enQueue(QueueArray *Queue, int data)
{
	if (Queue == NULL) // If the Queue doesn't exist...
	{
		printf("There is no Queue.\n\n");
		return;
	}
	else if (Queue->rear == Queue->size - 1) // If the Queue is full...
	{
		printf("The Queue is full.\n\n");
		return;
	}
	else
	{
		if (Queue->front == -1)
		{
			Queue->front = 0;
		}
		Queue->rear++;
		Queue->data[Queue->rear] = data;
		printQueue(Queue);
		return;
	}
}

int deQueue(QueueArray *Queue)
{
	if (Queue == NULL) // If the Queue doesn't exist...
	{
		printf("There is no Queue.\n\n");
		return -99999;
	}
	else if (Queue->front == -1) // If the Queue is empty...
	{
		printf("The Queue is empty.\n\n");
		return -99999;
	}
	else
	{
		int i = 0;
		for (i = 0; i < Queue->rear; i++) // Go through filled parts of Queue
		{
			Queue->data[i] = Queue->data[i + 1];
		}

		Queue->rear--;

		if (Queue->rear == -1) // Signal that Queue is empty if Queue becomes empty
		{
			Queue->front = -1;
		}

		printQueue(Queue);
		return Queue->data[0];
	}
}