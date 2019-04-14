#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#define TRUE 1
#define FALSE 0

List * newList(List *L)
{
	// Allocates memory for and creates Sentinel for Linked List
	L = (List*)malloc(sizeof(List));
	L->key = 0;
	L->next = L;
	L->prev = L;
	return L;
}

Node * newNode(Node *N, int key)
{
	// Allocates memory for and creates Node for Linked List
	N = (Node*)malloc(sizeof(Node));
	N->key = key;
	N->next = NULL;
	N->prev = NULL;
	return N;
}

int isEmpty(List *L)
{
	if (L->next == L) // If the sentinel is pointing towards itself...
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void printList(List *L)
{
	if (L == NULL)
	{
		return;
	}
	if (isEmpty(L))
	{
		return;
	}
	else
	{
		L = L->next; // Move away from sentinel
		while (L != NULL) // Print out each element in List
		{
			printf("%d ", L->key);
			L = L->next;
		}
		printf("\n");
		return;
	}
}

int insert(List *L, Node *N)
{
	if (L == NULL) // If List doesn't exist...
	{
		printf("Can't insert into list, list is null.\n\n");
		return FALSE;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		L->next = N;
		N->prev = L;
		return TRUE;
	}
	else
	{
		while (L->next != NULL) // Go through List
		{
			L = L->next;
		}
		L->next = N;
		N->prev = L;
		return TRUE;
	}
}

Node * search(List *L, int key)
{
	if (L == NULL) // If List doesn't exist...
	{
		return NULL;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		return NULL;
	}
	else
	{
		L = L->next; // Move away from sentinel
		while (L != NULL)
		{
			if (L->key == key)
			{
				return L;
			}
			L = L->next;
		}
		return NULL;
	}
}

Node * delete(List *L, Node *N)
{
	if (L == NULL) // If List doesn't exist...
	{
		printf("Can't delete from list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		printf("Can't delete, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next; // Move away from sentinel
		while (L != NULL)
		{
			if (L == N)
			{
				if (L->next == NULL)
				{
					L = L->prev;
					L->next = NULL;
					N->prev = NULL;
					return N;
				}
				else
				{
					L = L->prev;
					L->next = L->next->next;
					L = L->next;
					L->prev = L->prev->prev;
					N->next = NULL;
					N->prev = NULL;
					return N;
				}
			}
			L = L->next;
		}
		printf("Can't find node in list.\n\n");
		return NULL;
	}
}

Node * maximum(List *L)
{
	if (L == NULL) // If List doesn't exist...
	{
		printf("Can't find maximum from list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		printf("Can't find maximum, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next; // Move away from sentinel
		Node * Dummy;
		Dummy = L;
		while (L != NULL)
		{
			if (L->key > Dummy->key)
			{
				Dummy = L;
			}
			L = L->next;
		}
		return Dummy;
	}
}

Node * minimum(List *L)
{
	if (L == NULL) // If List doesn't exist...
	{
		printf("Can't find minimum from list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		printf("Can't find minimum, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next; // Move away from sentinel
		Node * Dummy;
		Dummy = L;
		while (L != NULL)
		{
			if (L->key < Dummy->key)
			{
				Dummy = L;
			}
			L = L->next;
		}
		return Dummy;
	}
}

Node * successor(List *L, Node *N)
{
	if (L == NULL) // If List doesn't exist...
	{
		return NULL;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		return NULL;
	}
	else
	{
		L = L->next; // Move away from sentinel
		int foundmatch = FALSE;
		Node * Dummy = NULL;
		Dummy = newNode(Dummy, 0);
		Dummy = maximum(L);
		while (L != NULL)
		{
			if ((L->key > N->key) && (L->key < Dummy->key))
			{
				Dummy = L;
				foundmatch = TRUE;
			}
			L = L->next;
		}
		if (foundmatch == TRUE) // If a successor was found during the search...
		{
			return Dummy;
		}
		else // If no successor was found during the search...
		{
			return NULL;
		}
	}
}

Node * predecessor(List *L, Node *N)
{
	if (L == NULL) // If List doesn't exist...
	{
		return NULL;
	}
	else if (isEmpty(L)) // If List is empty...
	{
		return NULL;
	}
	else
	{
		L = L->next; // Move away from sentinel
		int foundmatch = FALSE;
		Node * Dummy = NULL;
		Dummy = newNode(Dummy, 0);
		Dummy = minimum(L);
		while (L != NULL)
		{
			if ((L->key < N->key) && (L->key > Dummy->key))
			{
				Dummy = L;
				foundmatch = TRUE;
			}
			L = L->next;
		}
		if (foundmatch == TRUE) // If a predecessor was found during the search...
		{
			return Dummy;
		}
		else // If no predecessor was found during the search...
		{
			printf("Predecessor not found. Node is minimum. \n\n");
			return NULL;
		}
	}
}