#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define TRUE 1
#define FALSE 0

int isEmpty(List *L)
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

Node * getnewList(List *L)
{
	L = (List*)malloc(sizeof(List));
	L->key = 1;
	L->next = L;
	L->prev = L;
	return L;
}

Node * getnewNode(int key)
{
	// Create node and allocate memory
	Node * NewNode = (Node*)malloc(sizeof(Node));
	NewNode->key = key;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

int insert(List *L, Node *N) // Returns true if node is added to list, false if unsuccessful
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

Node * search(List *L, int number)
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
			if (L->key == number) // If N is found...
			{
				return L;
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

Node * delete(List *L, Node *N)
{
	if (isEmpty(L) == TRUE) // If the list is empty...
	{
		printf("Can't delete from empty list!\n\n");
		return NULL;
	}
	else if (L->next == N) // If the Node to be deleted is first in the list...
	{
		if (L->next->next == NULL) // If there's no node after the node to be deleted
		{
			L->next = L;
			return N;
		}
		else // If there is a node after the node to be deleted
		{
			L->next = L->next->next;
			L = L->next;
			L->prev = L->prev->prev;
			N->next = NULL;
			N->prev = NULL;
			return N;
		}
	}
	else
	{
		L = search(L, N->key);
		if (L == NULL) // If the Node isn't in the list...
		{
			return NULL;
		}
		else // If the Node is in the list...
		{
			L = L->prev;
			L->next = L->next->next;
			if (L->next != NULL)
			{
				L = L->next;
				L->prev = L->prev->prev;
			}
			N->next = NULL;
			N->prev = NULL;
			return N; // Returns N if it is in the list
		}
	}
}

Node * maximum(List *L)
{
	int i;
	Node * Dummy;
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

Node * minimum(List *L) // Returns the node containing the smallest key
{
	int i;
	Node * Dummy;
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

Node * successor(List *L, Node *N) // Returns pointer to next node with bigger number
{
	int i = 0, searchint = 0, foundnumber = 0;
	Node * Temp = getnewNode(0);
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

Node * predecessor(List *L, Node *N) // Returns pointer to next node with smaller number
{
	int i = 0, searchint = 0, foundnumber = 0;
	Node * Temp = getnewNode(0);
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

void printList(List *L)
{
	if (isEmpty(L) == TRUE)
	{
		printf("List is empty!");
	}
	else 
	{
		L = L->next;
		while (L != NULL)
		{
			printf("%d ", L->key);
			L = L->next;
		}
	}
	printf("\n\n");
}