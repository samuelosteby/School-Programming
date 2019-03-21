#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "linkedlist.h"
#define TRUE 1
#define FALSE 0

// MADE BY: Samuel Östeby

int main()
{
	// EXERCISE 1
	// Graph functions
	printf("Exercise 1:\n");

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

	// Print graph
	printGraph(Graph);

	printf("\n");

	// Print amount of vertices in graph
	printf("The graph has %d vertices\n", getNumVertices(Graph));

	// Print amount of edges in graph
	printf("The graph has %d edges\n\n", getNumEdges(Graph));

	// Print out connected vertices
	List * Result = NULL;
	Result = getNeighbors(Graph, 2);
	printf("Vertex 2 has the following vertices connected to it: ");
	printList(Result);

	// Print out vertices with ingoing connections
	Result = getInNeighbors(Graph, 2);
	printf("Vertex 2 ingoing connections from the following vertices: ");
	printList(Result);

	// Print out vertices with outgoing connections
	Result = getOutNeighbors(Graph, 2);
	printf("Vertex 2 has outgoing connections to the following vertices: ");
	printList(Result);

	printf("\n");

	// Check whether there's an edge between vertex 0 and vertex 2
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

	// Check whether there's an edge between vertex 1 and vertex 2
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

	// Check whether there's an edge between vertex 3 and vertex 4
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

	printf("\n");


	// EXERCISE 2
	// Pathfinding
	printf("Exercise 2:\n");

	// Create a new graph equal to the one shown in the exercise instructions
	printf("Creating new map based on the one in the exercise instructions...\n\n");
	AListGraph *PathfindingGraph = getPathFindingMap();

	// Use Dijkstra's algorithm to find shortest path from node 0 to node 50 (1,1 to 6,1)
	dijkstrapathfinding(PathfindingGraph, 0, 50);
	printf("\n\n");


	// EXERCISE 3
	// Strongly connected components
	printf("Exercise 3:\n");
	printf("Strongly connected components in TestGraph: \n");

	// Create the TestGraph
	AListGraph *TestGraph = createGraph(5);
	addDirectedEdge(TestGraph, 1, 0, 1);
	addDirectedEdge(TestGraph, 0, 2, 1);
	addDirectedEdge(TestGraph, 2, 1, 1);
	addDirectedEdge(TestGraph, 0, 3, 1);
	addDirectedEdge(TestGraph, 3, 4, 1);

	// Print strongly connected components from TestGraph
	printStronglyCC(TestGraph);
	printf("\n");
	printf("SCC in TestGraph2: \n");

	AListGraph *TestGraph2 = createGraph(8);
	addDirectedEdge(TestGraph2, 0, 1, 1);
	addDirectedEdge(TestGraph2, 1, 2, 1);
	addDirectedEdge(TestGraph2, 2, 0, 1);
	addDirectedEdge(TestGraph2, 2, 3, 1);
	addDirectedEdge(TestGraph2, 3, 4, 1);
	addDirectedEdge(TestGraph2, 4, 5, 1);
	addDirectedEdge(TestGraph2, 5, 3, 1);
	addUndirectedEdge(TestGraph2, 6, 7, 1);
	printStronglyCC(TestGraph2);

	printf("\n\n");


	// EXERCISE 4
	// Use Dijsktra's algorithm to find all distances to given vertex
	printf("Exercise 4:\n");
	printf("\nDistances in PathfindingGraph:\n");
	dijkstrashortestpath(PathfindingGraph, 0);

	printf("\nDistances in TestGraph2:\n");
	dijkstrashortestpath(TestGraph2, 5);

	printf("\n");
	system("pause");
}