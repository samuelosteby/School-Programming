#include <stdio.h>
#include "stackarray.h"

int addtostack(int data)
{
	if (tracker == -1)
	{
		tracker = 0;
		stackArray[0] = data;
		printf("%d was added to stack!\n\n", data);
		return TRUE;
	}
	else if (tracker == SIZE - 1)
	{
		printf("Stack is full!\n\n");
		return FALSE;
	}
	else
	{
		tracker++;
		stackArray[tracker] = data;
		printf("%d was added to stack!\n\n", data);
		return TRUE;
	}
}

int readstack()
{
	int result = 0, i = 0;

	if (tracker == -1)
	{
		printf("Stack is empty!\n\n");
		return -999;
	}
	else
	{
		result = stackArray[tracker];
		tracker--;
		printf("Returning %d\n\n", result);
		return result;
	}
}