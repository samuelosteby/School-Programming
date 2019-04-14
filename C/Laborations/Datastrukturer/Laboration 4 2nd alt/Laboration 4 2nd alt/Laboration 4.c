//Hampus Tuokkola

#include "stdio.h"
#include "stdlib.h"
#include "dijsktra.h"
#include "graph.h"
#include "llist.h"
#include "scc.h"
#define TRUE 1
#define FALSE 0

int main()
{
	//Creates Graph1
	AdjListGraph * Graph1 = createGraph(8);

	//Adds Undirected and Directed edges
	addUndirectedEdge(Graph1, 0, 3, 1);
	addUndirectedEdge(Graph1, 1, 7, 1);
	addUndirectedEdge(Graph1, 5, 6, 1);

	addDirectedEdge(Graph1, 2, 0, 1);
	addDirectedEdge(Graph1, 2, 1, 1);
	addDirectedEdge(Graph1, 3, 2, 1);
	addDirectedEdge(Graph1, 4, 7, 1);
	addDirectedEdge(Graph1, 7, 2, 1);

	//Prints out Graph1
	printGraph(Graph1);

	//Testing functions on Graph1
	printf("There are %d vertices in Graph1. \n", getNumVertices(Graph1));

	printf("There are %d edges in Graph1. \n",  getNumEdges(Graph1));

	List * Neighbors = NULL;
	Neighbors = getNeighbors(Graph1, 2);
	printf("Vertex 2 has the follow connections in Graph1. \n");
	printList(Neighbors);

	Neighbors = getInNeighbors(Graph1, 2);
	printf("Vertex 2 has the follow in connections in Graph1. \n");
	printList(Neighbors);

	Neighbors = getOutNeighbors(Graph1, 2);
	printf("Vertex 2 has the follow out connections in Graph1. \n");
	printList(Neighbors);

	if (hasEdge(Graph1, 2, 0) == TRUE)
	{
		printf("There is an edge between 2 and 0.\n");
	}
	else
	{
		printf("There is no edge between 2 and 0.\n");
	}

	if (hasEdge(Graph1, 3, 0) == TRUE)
	{
		printf("There is an edge between 3 and 0.\n");
	}
	else
	{
		printf("There is no edge between 3 and 0.\n");
	}

	if (hasEdge(Graph1, 4, 0) == TRUE)
	{
		printf("There is an edge between 4 and 0.\n");
	}
	else
	{
		printf("There is no edge between 4 and 0.\n");
	}



	//Exercise 2

	AdjListGraph * mapGraph = newPath();

	dijsktra(mapGraph, 0, 50);

	//Exercise 3

	//Creates a new graph
	AdjListGraph * Graph2 = createGraph(8);

	//Adds Undirected and Directed edges
	addUndirectedEdge(Graph2, 0, 3, 1);
	addUndirectedEdge(Graph2, 1, 7, 1);
	addUndirectedEdge(Graph2, 5, 6, 1);

	addDirectedEdge(Graph2, 2, 0, 1);
	addDirectedEdge(Graph2, 2, 1, 1);
	addDirectedEdge(Graph2, 3, 2, 1);
	addDirectedEdge(Graph2, 4, 7, 1);
	addDirectedEdge(Graph2, 7, 2, 1);

	printGraph(Graph2);
	printSCC(Graph2);

	//Exercise 4

	dijsktraSP(mapGraph, 0);


	system("pause");
}