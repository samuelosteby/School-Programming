#include <stdio.h>
#include "queuearray.h"

int addtoqueue(int data)
{
	if (rear == SIZE - 1)
	{
		printf("Queue is full!\n\n");
		return FALSE;
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}

		rear++;
		arrayQueue[rear] = data;
		printf("Added %d to queue!\n\n", data);
		return TRUE;
	}
}

int readqueue()
{
	int result, i;
	if (front == -1)
	{
		printf("The queue is empty!\n\n");
		return -999;
	}
	else
	{
		result = arrayQueue[0];

		for (i = 0; i < rear; i++)
		{
			arrayQueue[i] = arrayQueue[i + 1];
		}

		rear--;

		if (rear == -1)
		{
			front = -1;
		}

		printf("Returning %d\n\n", result);
		return result;
	}
}