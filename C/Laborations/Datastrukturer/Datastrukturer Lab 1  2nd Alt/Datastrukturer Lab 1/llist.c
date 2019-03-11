#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#define TRUE 1
#define FALSE 0

List * newList(List *L)
{
	//Allocates memory and creates sentinel.
	L = (List*)malloc(sizeof(List)); 
	L->key = 0;
	L->next = L;
	L->prev = L;
	return L;
}

Node * newNode(Node *N, int key)
{
	//Allocates memory and creates a node.
	N = (Node*)malloc(sizeof(Node));
	N->key = key;
	N->next = NULL;
	N->prev = NULL;
	return N;
}

int isEmpty(List *L)
{
	if (L->next == L)
	{
		return TRUE;
	}
	return FALSE;
}

void printList(List *L)
{
	//Prints out keys from list if not empty.
	if (isEmpty(L))
	{
		return;
	}
	else
	{
		L = L->next;
		while (L != NULL)
		{
			printf("%d ", L->key);
			L = L->next;
		}
		printf("\n\n");
		return;
	}
}

int insert(List *L, Node *N)
{
	if (L == NULL)
	{
		printf("Can't insert into list, list is null.\n\n");
		return FALSE;
	}
	else if (isEmpty(L))
	{
		L->next = N;
		N->prev = L;
		return TRUE;
	}
	else
	{
		while (L->next != NULL)
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
	if (L == NULL)
	{
		printf("Can't search in list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L))
	{
		printf("Can't search, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		while (L != NULL)
		{
			if (L->key == key)
			{
				return L;
			}
			L = L->next;
		}
		printf("Could not find key in list.\n\n");
		return NULL;
	}
}

Node * delete(List *L, Node *N)
{
	if (L == NULL)
	{
		printf("Can't delete from list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L))
	{
		printf("Can't delete, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
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
	if (L == NULL)
	{
		printf("Can't find maximum from list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L))
	{
		printf("Can't find maximum, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		Node * Temp;
		Temp = L;
		while (L != NULL)
		{
			if (L->key > Temp->key)
			{
				Temp = L;
			}
			L = L->next;
		}
		return Temp;
	}
}

Node * minimum(List *L)
{
	if (L == NULL)
	{
		printf("Can't find minimum from list, list is null.\n\n");
		return NULL;
	}
	else if (isEmpty(L))
	{
		printf("Can't find minimum, list is empty.\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		Node * Temp;
		Temp = L;
		while (L != NULL)
		{
			if (L->key < Temp->key)
			{
				Temp = L;
			}
			L = L->next;
		}
		return Temp;
	}
}

Node * successor(List *L, Node *N)
{
	if (L == NULL)
	{
		return NULL;
	}
	else if (isEmpty(L))
	{
		return NULL;
	}
	else
	{
		L = L->next;
		int matchfound = FALSE;
		Node * Temp = NULL;
		Temp = newNode(Temp, 0);
		Temp = maximum(L);
		while (L != NULL)
		{
			if ((L->key > N->key) && (L->key < Temp->key))
			{
				Temp = L;
				matchfound = TRUE;
			}
			L = L->next;
		}
		if (matchfound == TRUE)
		{
			return Temp;
		}
		else
		{
			return NULL;
		}
	}
}

Node * predecessor(List *L, Node *N)
{
	if (L == NULL)
	{
		return NULL;
	}
	else if (isEmpty(L))
	{
		return NULL;
	}
	else
	{
		L = L->next;
		int matchfound = FALSE;
		Node * Temp = NULL;
		Temp = newNode(Temp, 0);
		Temp = minimum(L);
		while (L != NULL)
		{
			if ((L->key < N->key) && (L->key > Temp->key))
			{
				Temp = L;
				matchfound = TRUE;
			}
			L = L->next;
		}
		if (matchfound == TRUE)
		{
			return Temp;
		}
		else
		{
			printf("Predecessor not found. Node was already minimum. \n\n");
			return NULL;
		}
	}
}