#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "linkedlist.h"
#define TRUE 1
#define FALSE 0

int main()
{
	// Create graph with given amount of vertices
	int vertices = 5;
	AListGraph *Graph = createGraph(5);

	// Add undirected edges to graph
	addUndirectedEdge(Graph, 0, 1);
	addUndirectedEdge(Graph, 0, 4);
	addUndirectedEdge(Graph, 1, 3);
	addUndirectedEdge(Graph, 1, 4);
	addUndirectedEdge(Graph, 2, 3);
	addUndirectedEdge(Graph, 3, 4);

	// Add directed edges to graph
	addDirectedEdge(Graph, 0, 2);
	addDirectedEdge(Graph, 2, 4);

	// Print graph
	printGraph(Graph);

	printf("\n");

	// Print amount of vertices in graph
	printf("The graph has %d vertices\n", getNumVertices(Graph));

	// Print amount of edges in graph
	printf("The graph has %d edges\n\n", getNumEdges(Graph));

	List * Result = NULL;
	Result = getNeighbors(Graph, 2);
	printf("Vertex 2 has the following vertices connected to it: ");
	printList(Result);

	Result = getInNeighbors(Graph, 2);
	printf("Vertex 2 ingoing connections from the following vertices: ");
	printList(Result);

	Result = getOutNeighbors(Graph, 2);
	printf("Vertex 2 has outgoing connections to the following vertices: ");
	printList(Result);

	int matchfound = FALSE;

	printf("Checking if vertex 0 and vertex 2 have an edge...\n");
	printf("The result is: ");
	if (hasEdge(Graph, 0, 2) == TRUE)
	{
		printf("TRUE\n\n");
	}
	else
	{
		printf("FALSE\n\n");
	}

	printf("Checking if vertex 1 and vertex 2 have an edge...\n");
	printf("The result is: ");
	if (hasEdge(Graph, 1, 2) == TRUE)
	{
		printf("TRUE\n\n");
	}
	else
	{
		printf("FALSE\n\n");
	}

	printf("Checking if vertex 3 and vertex 4 have an edge...\n");
	printf("The result is: ");
	if (hasEdge(Graph, 3, 4) == TRUE)
	{
		printf("TRUE\n\n");
	}
	else
	{
		printf("FALSE\n\n");
	}

	system("pause");
}