#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "linkedlist.h"
#define TRUE 1
#define FALSE 0

// MADE BY: Samuel Östeby

int main()
{
	// Create graph with given amount of vertices
	int vertices = 5;
	AListGraph *Graph = createGraph(5);

	// Add undirected edges to graph
	addUndirectedEdge(Graph, 0, 1, 1);
	addUndirectedEdge(Graph, 0, 4, 1);
	addUndirectedEdge(Graph, 1, 3, 1);
	addUndirectedEdge(Graph, 1, 4, 1);
	addUndirectedEdge(Graph, 2, 3, 1);
	addUndirectedEdge(Graph, 3, 4, 1);

	// Add directed edges to graph
	addDirectedEdge(Graph, 0, 2, 1);
	addDirectedEdge(Graph, 2, 4, 1);
	addDirectedEdge(Graph, 2, 1, 1);

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

	printf("\n");

	int matchfound = FALSE;

	printf("Checking if vertex 0 and vertex 2 have an edge...\n");
	printf("The result is: ");
	if (hasEdge(Graph, 0, 2) == TRUE)
	{
		printf("TRUE\n");
	}
	else
	{
		printf("FALSE\n");
	}

	printf("Checking if vertex 1 and vertex 2 have an edge...\n");
	printf("The result is: ");
	if (hasEdge(Graph, 1, 2) == TRUE)
	{
		printf("TRUE\n");
	}
	else
	{
		printf("FALSE\n");
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

	// Pathfinding
	printf("Pathfinding:\n");

	// Create a new graph equal to the one shown in the exercise instructions
	printf("Creating new map based on the one in the exercise instructions...\n\n");
	AListGraph *PathfindingGraph = getPathFindingMap();

	// Use Dijkstra's algorithm to find shortest path and print it
	dijkstrapathfinding(PathfindingGraph, 0, 50);

	printf("\nDistances:\n");

	// Use Dijsktra's algorithm to find all distances to given vertex
	dijkstrashortestpath(PathfindingGraph, 0);

	AListGraph *TestGraph = createGraph(5);
	addDirectedEdge(TestGraph, 1, 0, 1);
	addDirectedEdge(TestGraph, 0, 2, 1);
	addDirectedEdge(TestGraph, 2, 1, 1);
	addDirectedEdge(TestGraph, 0, 3, 1);
	addDirectedEdge(TestGraph, 3, 4, 1);

	printStronglyCC(TestGraph);

	system("pause");
}