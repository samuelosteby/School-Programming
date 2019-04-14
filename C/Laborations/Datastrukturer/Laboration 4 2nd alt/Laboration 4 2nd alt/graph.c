#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#define TRUE 1
#define FALSE 0

AdjListNode * newAdjListNode(int destination, int weight)
{
	//Creates a new adjacency list node and allocates memory.
	AdjListNode * AdjNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	AdjNode->destination = destination;
	AdjNode->weight = weight;
	AdjNode->next = NULL;
	return AdjNode;
}

AdjListGraph * createGraph(int vertices)
{
	//Creates an new adjacency list graph with input amoumt of vertices and allocates memory for it.
	AdjListGraph * newGraph = (AdjListGraph*)malloc(sizeof(AdjListGraph));
	newGraph->vertices = vertices;
	newGraph->array = (AdjList*)malloc(newGraph->vertices * sizeof(AdjList));

	//Sets edges in graph to 0
	newGraph->edges = 0;

	//Sets every head to NULL.
	for (int i = 0; i < newGraph->vertices; i++)
	{
		newGraph->array[i].head = NULL;
	}
	return newGraph;
}

void addUndirectedEdge(AdjListGraph *G, int source, int destination, int weight)
{
	int canaddedge = 0;

	if ((hasEdge(G, source, destination) == FALSE))
	{
		// Add an edge from the source to the destination
		AdjListNode * AdjNode = newAdjListNode(destination, weight);
		AdjNode->next = G->array[source].head;
		G->array[source].head = AdjNode;

		// Add an edge from the destination to the source, to make it undirected
		AdjNode = newAdjListNode(source, weight);
		AdjNode->next = G->array[destination].head;
		G->array[destination].head = AdjNode;

		G->edges++;
	}
}

void addDirectedEdge(AdjListGraph *G, int source, int destination, int weight)
{
	if ((hasEdge(G, source, destination) == FALSE))
	{
		// Add an edge from the source to the destination
		AdjListNode * AdjNode = newAdjListNode(destination, weight);
		AdjNode->next = G->array[source].head;
		G->array[source].head = AdjNode;
		G->edges++;
	}
}

void printGraph(AdjListGraph *G)
{
	//Iterates through all lists in the array, then prints them out.
	for (int vertices = 0; vertices < G->vertices; vertices++)
	{
		AdjListNode *TempNode = G->array[vertices].head;
		printf("%d connects to", vertices);
		while (TempNode != NULL)
		{
			printf("  %d", TempNode->destination);
			TempNode = TempNode->next;
		}
		printf("\n");
	}
}

int getNumVertices(AdjListGraph *G)
{
	return G->vertices;
}

int getNumEdges(AdjListGraph *G)
{

	return G->edges;
}

List * getNeighbors(AdjListGraph *G, int vertex)
{
	List * Neighbors = NULL;
	Neighbors = newList(Neighbors);
	Node * NeighborNode = NULL;
	AdjListNode * TempNode = NULL;
	//Iterates through all lists except input vertex to find ingoing and add them to Neigbors.
	for (int vertices = 0; vertices < G->vertices; vertices++)
	{
		if (vertices != vertex)
		{
			TempNode = G->array[vertices].head;
			while (TempNode != NULL) //Continues to loop until end of line
			{
				if (TempNode->destination == vertex)
				{
					NeighborNode = newNode(NeighborNode, vertices);
					insert(Neighbors, NeighborNode);
				}
				TempNode = TempNode->next;
			}
		}
	}

	//Iterates in the same way except to find outgoing.
	TempNode = G->array[vertex].head;
	while (TempNode != NULL)
	{
		if (search(Neighbors, TempNode->destination) == NULL)
		{
			NeighborNode = newNode(NeighborNode, TempNode->destination);
			insert(Neighbors, NeighborNode);
		}

		TempNode = TempNode->next;
	}

	return Neighbors;
}

List * getInNeighbors(AdjListGraph *G, int vertex)
{
	//InNeighbors half of Neighbors function
	List * Result = NULL;
	Result = newList(Result);
	Node * TempResult = NULL;
	AdjListNode * Temp = NULL;

	for (int vertices = 0; vertices < G->vertices; vertices++)
	{
		if (vertices != vertex)
		{
			Temp = G->array[vertices].head;
			while (Temp != NULL)
			{
				if (Temp->destination == vertex)
				{
					TempResult = newNode(TempResult, vertices);
					insert(Result, TempResult);
				}

				Temp = Temp->next;
			}
		}
	}

	return Result;
}

List * getOutNeighbors(AdjListGraph *G, int vertex)
{
	//OutNeighbors half of Neighbors function
	List * Result = NULL;
	Result = newList(Result);
	Node * TempResult = NULL;
	AdjListNode * Temp = NULL;

	Temp = G->array[vertex].head;
	while (Temp != NULL)
	{
		if (search(Result, Temp->destination) == NULL)
		{
			TempResult = newNode(TempResult, Temp->destination);
			insert(Result, TempResult);
		}

		Temp = Temp->next;
	}

	return Result;
}

int hasEdge(AdjListGraph *G, int v1, int v2)
{
	int foundmatch = FALSE;
	Node * TempResult = NULL;
	AdjListNode * TempNode = NULL;

	//Iterates through v1 outlist
	TempNode = G->array[v1].head;
	while (TempNode != NULL)
	{
		if (TempNode->destination == v2)
		{
			foundmatch = TRUE;
		}
		TempNode = TempNode->next;
	}

	if (foundmatch == FALSE)
	{
		//Iterates through v2 outlist 
		TempNode = G->array[v2].head;
		while (TempNode != NULL)
		{
			if (TempNode->destination == v1)
			{
				foundmatch = TRUE;
			}

			TempNode = TempNode->next;
		}
	}
	return foundmatch;
}



