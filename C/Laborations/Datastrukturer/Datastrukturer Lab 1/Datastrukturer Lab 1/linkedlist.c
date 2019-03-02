#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define TRUE 1
#define FALSE 0

int isEmpty(struct Node *L)
{
	if (L->next == L)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

struct Node * getnewList(struct Node *L)
{
	L = (struct Node*)malloc(sizeof(struct Node));
	L->key = 1;
	L->next = L;
	L->prev = L;
	return L;
}

struct Node * getnewNode(int key)
{
	// Create node and allocate memory
	struct Node * NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->key = key;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

int insert(struct Node *L, struct Node *N) // Returns true if node is added to list, false if unsuccessful
{
	if (isEmpty(L) == 1) // If the list is empty...
	{
		L->next = N;
		return TRUE;
	}
	else // If the list isn't empty...
	{
		L = L->next;
		while (L->next != NULL)
		{
			L = L->next;
		}

		L->next = N;
		N->prev = L;
		return TRUE;
	}

	// If we somehow didn't recieve proper values for the function and the insertion fails...
	return FALSE;
}

struct Node * search(struct Node *L, struct Node *N)
{
	if (isEmpty(L) == TRUE) // If the list is empty...
	{
		return NULL;
	}
	else // If the list isn't empty...
	{
		L = L->next;
		while (L != NULL)
		{
			if (L == N) // If N is found...
			{
				return N;
			}
			else // If N isn't the current Node
			{
				// Look at the next Node
				L = L->next;
			}
		}

		// If N isn't in L...
		return NULL;
	}
}

struct Node * delete(struct Node *L, struct Node *N)
{
	struct Node * Dummy;
	if (isEmpty(L) == TRUE) // If the list is empty...
	{
		printf("Can't delete from empty list!\n\n");
		return NULL;
	}
	else if (L->next == N) // If the Node to be deleted is first in the list...
	{
		L->next = L;
		return N;
	}
	else
	{
		L = L->next;
		Dummy = search(L, N);
		if (Dummy == NULL) // If the Node isn't in the list...
		{
			return NULL;
		}
		else // If the Node is in the list...
		{
			Dummy->prev->next = Dummy->next;
			Dummy->next->prev = Dummy->prev;
			return N; // Returns N if it is in the list
		}
	}
}

struct Node * maximum(struct Node *L)
{
	int i;
	struct Node * Dummy;
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		printf("Maximum problem: Link is empty!\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = L->key;
		Dummy = L;
		L = L->next;

		while (L != NULL)
		{
			if (L->key > i)
			{
				i = L->key;
				Dummy = L;
			}
			L = L->next;
		}

		return Dummy; // pointer to Node containing biggest key
	}
}

struct Node * minimum(struct Node *L) // Returns the node containing the smallest key
{
	int i;
	struct Node * Dummy;
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		return NULL;
	}
	else
	{
		L = L->next;
		i = L->key;
		Dummy = L;
		L = L->next;

		while (L != NULL)
		{
			if (L->key < i)
			{
				i = L->key;
				Dummy = L;
			}
			L = L->next;
		}

		return Dummy; // pointer to Node containing smallest key
	}
}

struct Node * successor(struct Node *L, struct Node *N) // Returns pointer to next node with bigger number
{
	int i = 0, searchint = 0, foundnumber = 0;
	struct Node * Temp = getnewNode(0);
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		printf("Oh no, the list is empty!\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = N->key;
		Temp = maximum(L);

		while (L != NULL)
		{
			if ((L->key > i) && (L->key < Temp->key))
			{
				Temp = L;
				foundnumber = 1;
			}

			L = L->next;
		}

		if (foundnumber == 1)
		{
			return Temp;
		}
		else
		{
			return NULL; // N was the maximum already
		}
	}
}

struct Node * predecessor(struct Node *L, struct Node *N) // Returns pointer to next node with smaller number
{
	int i = 0, searchint = 0, foundnumber = 0;
	struct Node * Temp = getnewNode(0);
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		printf("Oh no, the list is empty!\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = N->key;
		Temp = minimum(L);

		while (L != NULL)
		{
			if ((L->key < i) && (L->key > Temp->key))
			{
				Temp = L;
				foundnumber = 1;
			}

			L = L->next;
		}

		if (foundnumber == 1)
		{
			return Temp;
		}
		else
		{
			return NULL; // N was the maximum already
		}
	}
}