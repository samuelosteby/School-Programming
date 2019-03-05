#include <stdio.h>
#include <stdlib.h>
#include "queuearray.h"

Queue_array * getnewQueue(Queue_array *Queue, int size)
{
	Queue = (Queue_array*)malloc(sizeof(Queue_array));
	Queue->size = size;
	Queue->data = (int*)malloc(sizeof(int) * Queue->size);
	Queue->front = -1;
	Queue->rear = -1;
	return Queue;
}

int enqueue(Queue_array *Queue, int data)
{
	if (Queue->rear == Queue->size - 1)
	{
		printf("Queue is full!\n\n");
		return FALSE;
	}
	else
	{
		if (Queue->front == -1)
		{
			Queue->front = 0;
		}

		Queue->rear = Queue->rear + 1;
		Queue->data[Queue->rear] = data;
		printf("Added %d to queue!\n\n", data);

		printQueue(Queue);
		return TRUE;
	}
}

int dequeue(Queue_array *Queue)
{
	int result, i;
	if (Queue->front == -1)
	{
		printf("The queue is empty!\n\n");
		return -999;
	}
	else
	{
		result = Queue->data[0];

		for (i = 0; i < Queue->rear; i++)
		{
			Queue->data[i] = Queue->data[i + 1];
		}

		Queue->rear = Queue->rear - 1;

		if (Queue->rear == -1)
		{
			Queue->front = -1;
		}

		printf("Returning %d\n\n", result);
		printQueue(Queue);
		return result;
	}
}

void printQueue(Queue_array *Queue)
{
	if (Queue->front == -1)
	{
		printf("The queue is empty!\n\n");
	}
	else
	{
		printf("The queue: ");
		int i;
		for (i = 0; i <= Queue->rear; i++)
		{
			printf("%d ", Queue->data[i]);
		}
		printf("\n\n");
	}
}