#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "scc.h"
#define TRUE 1
#define FALSE 0


void DFS(AdjListGraph *Graph, int vertex, int visited[])
{
	visited[vertex] = TRUE;
	printf("%d ", vertex);

	AdjListNode * Temp = Graph->array[vertex].head;

	while (Temp != NULL)
	{
		if (visited[Temp->destination] == FALSE)
		{
			DFS(Graph, Temp->destination, visited);
		}
		Temp = Temp->next;
	}
}

AdjListGraph * transposeGraph(AdjListGraph *Graph)
{
	AdjListGraph * Temp = createGraph(Graph->vertices);
	AdjListNode * TempNode = NULL;
	AdjListNode * TempNode2 = NULL;
	int foundundirected = FALSE;

	// Loop through all of a vertex's connection. If a connection is found, check whether it's a directed or an undirected edge
	// Connect the edge in reverse in the reverse graph if it's a directed one found
	for (int i = 0; i < Graph->vertices; i++)
	{
		TempNode = Graph->array[i].head;
		while (TempNode != NULL)
		{
			foundundirected = FALSE;
			TempNode2 = Graph->array[TempNode->destination].head;
			while (TempNode2 != NULL)
			{
				if (TempNode2->destination == i) // If the edge is an undirected edge because it's found on the other vertex too...
				{
					addUndirectedEdge(Temp, i, TempNode->destination, 1);
					foundundirected = TRUE;
				}
				TempNode2 = TempNode2->next;
			}

			if (foundundirected == FALSE) // If the edge isn't undirected, add a reversed edge to second graph
			{
				addDirectedEdge(Temp, TempNode->destination, i, 1);
			}

			TempNode = TempNode->next;
		}
	}

	return Temp;
}

VStack * newStack(int capacity)
{
	VStack * Stack = (VStack*)malloc(sizeof(VStack));
	Stack->capacity = capacity;
	Stack->array = (int*)malloc(sizeof(int) * Stack->capacity);
	Stack->tracker = -1;
	return Stack;
}

int emptyStack(VStack *Stack)
{
	if (Stack->tracker == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void pushStack(VStack *Stack, int data)
{
	if (Stack->tracker == Stack->capacity) // If the stack is full...
	{
		printf("Stack is full!\n");
		return;
	}

	Stack->tracker++;
	Stack->array[Stack->tracker] = data;
}

int popStack(VStack *Stack)
{
	Stack->tracker--;
	return Stack->array[Stack->tracker + 1];
}

void fillStack(AdjListGraph *Graph, int vertex, int visited[], VStack *Stack)
{
	visited[vertex] = TRUE;

	AdjListNode * Temp = Graph->array[vertex].head;

	// Recursively fill stack with vertices
	while (Temp != NULL)
	{
		if (visited[Temp->destination] == FALSE)
		{
			fillStack(Graph, Temp->destination, visited, Stack);
		}
		Temp = Temp->next;
	}

	// Push the given vertex into the stack
	pushStack(Stack, vertex);
}

void printSCC(AdjListGraph *Graph)
{
	VStack * Stack = newStack(Graph->vertices);

	int *visited = (int*)malloc(sizeof(int) * Graph->vertices);
	int i = 0;

	// Mark all vertices as unvisited for the first depth first search
	for (i = 0; i < Graph->vertices; i++)
	{
		visited[i] = FALSE;
	}

	// Fill the stack with vertices according to their finishing times
	for (i = 0; i < Graph->vertices; i++)
	{
		if (visited[i] == FALSE)
		{
			fillStack(Graph, i, visited, Stack);
		}
	}

	// Create a transposed version of the graph
	AdjListGraph * Reverse = transposeGraph(Graph);

	// Mark all vertices as unvisited for the second depth first search
	for (i = 0; i < Graph->vertices; i++)
	{
		visited[i] = FALSE;
	}

	// Go through all vertices in the stack order and print the SSC of the popped vertex
	while (emptyStack(Stack) == FALSE)
	{
		int vertex = popStack(Stack);

		if (visited[vertex] == FALSE)
		{
			DFS(Reverse, vertex, visited);
			printf("\n");
		}
	}
}