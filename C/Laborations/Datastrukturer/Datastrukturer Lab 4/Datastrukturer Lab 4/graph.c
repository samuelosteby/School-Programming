#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define TRUE 1
#define FALSE 0

AListNode * getNewAListNode(int dest)
{
	// Allocate memory for and create new adjaceny list node
	AListNode * NewNode = (AListNode*)malloc(sizeof(AListNode));
	NewNode->dest = dest;
	NewNode->next = NULL;
	return NewNode;
}

AListGraph * createGraph(int vertices)
{
	// Allocate memory for and create new adjaceny list graph with given amount of vertices
	AListGraph * Graph = (AListGraph*)malloc(sizeof(AListGraph));
	Graph->vertices = vertices;

	// Allocate memory for array based on amount of vertices
	Graph->array = (AList*)malloc(Graph->vertices * sizeof(AList));

	// Initialize every adjaceny list with head as NULL
	for (int i = 0; i < Graph->vertices; i++)
	{
		Graph->array[i].head = NULL;
	}

	return Graph;
}

void addUndirectedEdge(AListGraph *Graph, int src, int dest)
{
	// Add an edge from the source to the destination
	AListNode * NewNode = getNewAListNode(dest);
	NewNode->next = Graph->array[src].head;
	Graph->array[src].head = NewNode;

	// Add an edge from the destination to the source, to make it undirected
	NewNode = getNewAListNode(src);
	NewNode->next = Graph->array[dest].head;
	Graph->array[dest].head = NewNode;
}

void addDirectedEdge(AListGraph *Graph, int src, int dest)
{
	// Add an edge from the source to the destination
	AListNode * NewNode = getNewAListNode(dest);
	NewNode->next = Graph->array[src].head;
	Graph->array[src].head = NewNode;
}

void printGraph(AListGraph *Graph)
{
	printf("The graph:\n");

	// Goes through every list in the array and print the lists out
	for (int vertices = 0; vertices < Graph->vertices; vertices++)
	{
		AListNode *Temp = Graph->array[vertices].head;
		printf("%d", vertices);
		while (Temp != NULL)
		{
			printf(" -> %d", Temp->dest);
			Temp = Temp->next;
		}
		printf("\n");
	}
}

int getNumVertices(AListGraph *Graph)
{
	return Graph->vertices;
}

int getNumEdges(AListGraph *Graph)
{
	int edges = 0;
	AListNode *Temp = NULL;

	// Goes through each list in the array and counts the amount of jumps between nodes
	for (int vertices = 0; vertices < Graph->vertices; vertices++)
	{
		Temp = Graph->array[vertices].head;
		while (Temp != NULL)
		{
			edges++;
			Temp = Temp->next;
		}
	}

	return edges;
}

List * getNeighbors(AListGraph *Graph, int vertex)
{
	List * Result = NULL;
	Result = getNewList(Result);
	Node * TempResult = NULL;
	AListNode * Temp = NULL;

	// Goes through all lists in the array except the inputed one to find ingoing connections to add them to the result list
	for (int vertices = 0; vertices < Graph->vertices; vertices++)
	{
		if (vertices != vertex) // If the vertex being checked isn't the inputted one...
		{
			Temp = Graph->array[vertices].head;
			while (Temp != NULL) // While still not at the end of list...
			{
				if (Temp->dest == vertex) // If the next node in the list is the vertex we're looking for...
				{
					// Create new node with value of the head of the list and input node into result list
					TempResult = getNewNode(TempResult, vertices);
					insert(Result, TempResult);
				}

				Temp = Temp->next;
			}
		}
	}

	// Goes through the inputed vertex's list of outgoing connections to add them to the result list
	Temp = Graph->array[vertex].head;
	while (Temp != NULL) // While still not at the end of list...
	{
		if (search(Result, Temp->dest) == NULL) // If the node isn't already in the result list...
		{
			// Create new node with value of the head of the list and input node into result list
			TempResult = getNewNode(TempResult, Temp->dest);
			insert(Result, TempResult);
		}

		Temp = Temp->next;
	}

	return Result;
}

List * getInNeighbors(AListGraph *Graph, int vertex)
{
	List * Result = NULL;
	Result = getNewList(Result);
	Node * TempResult = NULL;
	AListNode * Temp = NULL;

	// Goes through all lists in the array except the inputed one to find ingoing connections to add them to the result list
	for (int vertices = 0; vertices < Graph->vertices; vertices++)
	{
		if (vertices != vertex) // If the vertex being checked isn't the inputted one...
		{
			Temp = Graph->array[vertices].head;
			while (Temp != NULL) // While still not at the end of list...
			{
				if (Temp->dest == vertex) // If the next node in the list is the vertex we're looking for...
				{
					// Create new node with value of the head of the list and input node into result list
					TempResult = getNewNode(TempResult, vertices);
					insert(Result, TempResult);
				}

				Temp = Temp->next;
			}
		}
	}

	return Result;
}

List * getOutNeighbors(AListGraph *Graph, int vertex)
{
	List * Result = NULL;
	Result = getNewList(Result);
	Node * TempResult = NULL;
	AListNode * Temp = NULL;

	// Goes through the inputed vertex's list of outgoing connections to add them to the result list
	Temp = Graph->array[vertex].head;
	while (Temp != NULL) // While still not at the end of list...
	{
		if (search(Result, Temp->dest) == NULL) // If the node isn't already in the result list...
		{
			// Create new node with value of the head of the list and input node into result list
			TempResult = getNewNode(TempResult, Temp->dest);
			insert(Result, TempResult);
		}

		Temp = Temp->next;
	}

	return Result;
}

int hasEdge(AListGraph *Graph, int vertex1, int vertex2)
{
	Node * TempResult = NULL;
	AListNode * Temp = NULL;
	int matchfound = FALSE;

	// Goes through vertex1's list of outgoing connections to see if the other vertex is there
	Temp = Graph->array[vertex1].head;
	while (Temp != NULL) // While still not at the end of list...
	{
		if (Temp->dest == vertex2)
		{
			matchfound = TRUE;
		}

		Temp = Temp->next;
	}

	if (matchfound == FALSE) // If an edge still hasn't been found...
	{
		// Goes through vertex2's list of outgoing connections to see if the other vertex is there
		Temp = Graph->array[vertex2].head;
		while (Temp != NULL) // While still not at the end of list...
		{
			if (Temp->dest == vertex1)
			{
				matchfound = TRUE;
			}

			Temp = Temp->next;
		}
	}

	return matchfound;
}