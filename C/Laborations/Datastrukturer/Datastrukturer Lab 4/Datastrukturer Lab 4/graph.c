#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#define TRUE 1
#define FALSE 0

AListNode * getNewAListNode(int dest, int weight)
{
	// Allocate memory for and create new adjaceny list node
	AListNode * NewNode = (AListNode*)malloc(sizeof(AListNode));
	NewNode->dest = dest;
	NewNode->weight = weight;
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

void addUndirectedEdge(AListGraph *Graph, int src, int dest, int weight)
{
	// Add an edge from the source to the destination
	AListNode * NewNode = getNewAListNode(dest, weight);
	NewNode->next = Graph->array[src].head;
	Graph->array[src].head = NewNode;

	// Add an edge from the destination to the source, to make it undirected
	NewNode = getNewAListNode(src, weight);
	NewNode->next = Graph->array[dest].head;
	Graph->array[dest].head = NewNode;
}

void addDirectedEdge(AListGraph *Graph, int src, int dest, int weight)
{
	// Add an edge from the source to the destination
	AListNode * NewNode = getNewAListNode(dest, weight);
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

MinHeapNode * getMinHeapNode(int vertex, int distance)
{
	// Allocate memory for, create and return Min Heap Node
	MinHeapNode * MHeapNode = (MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	MHeapNode->vertex = vertex;
	MHeapNode->distance = distance;
	return MHeapNode;
}

MinHeap * getMinHeap(int capacity)
{
	// Allocate memory for, create and return Min Heap
	MinHeap *MHeap = (MinHeap*)malloc(sizeof(MinHeap));
	MHeap->capacity = capacity;
	MHeap->position = (int*)malloc(MHeap->capacity * sizeof(int));
	MHeap->size = 0;
	MHeap->array = (MinHeapNode**)malloc(MHeap->capacity * sizeof(MinHeapNode*));
	return MHeap;
}

void swapMinHeapNode(MinHeapNode **x, MinHeapNode **y)
{
	MinHeapNode *Temp = *x;
	*x = *y;
	*y = Temp;
}

void minHeapTransform(MinHeap *MHeap, int vertex)
{
	int smallest = vertex, left = 1 + 2 * vertex, right = 2 + 2 * vertex;

	// Determines where the smallest vertex is
	if ((left < MHeap->size) && (MHeap->array[left]->distance < MHeap->array[smallest]->distance))
	{
		smallest = left;
	}
	if ((right < MHeap->size) && (MHeap->array[right]->distance < MHeap->array[smallest]->distance))
	{
		smallest = right;
	}

	// If the smallest isn't the inputted vertex...
	if (smallest != vertex)
	{
		// Creates new nodes to be swapped
		MinHeapNode *SmallestNode = MHeap->array[smallest];
		MinHeapNode *VertexNode = MHeap->array[vertex];

		// Swaps the positions
		MHeap->position[SmallestNode->vertex] = vertex;
		MHeap->position[VertexNode->vertex] = smallest;

		// Swaps the nodes
		swapMinHeapNode(&MHeap->array[smallest], &MHeap->array[vertex]);
		minHeapTransform(MHeap, smallest);
	}
}

int minHeapEmpty(MinHeap * MHeap)
{
	if (MHeap->size == 0)
	{
		return TRUE;
	}

	return FALSE;
}

MinHeapNode * extractMinHeap(MinHeap *MHeap)
{
	if (minHeapEmpty(MHeap))
	{
		return NULL;
	}

	// Store the Root Node and replace it with the last node
	MinHeapNode * Root = MHeap->array[0];

	MinHeapNode * LastNode = MHeap->array[MHeap->size - 1];
	MHeap->array[0] = LastNode;

	// Update position of last Node, reduce Heap size and transform Root
	MHeap->position[Root->vertex] = MHeap->size - 1;
	MHeap->position[LastNode->vertex] = 0;

	--MHeap->size; // LALALAL CHECK THIS LATER
	minHeapTransform(MHeap, 0);

	return Root;
}

void decreaseKey(MinHeap *MHeap, int vertex, int distance)
{
	// Get the index of vertex in Heap Array and then find the Node to update its distance
	int index = MHeap->position[vertex];
	MHeap->array[index]->distance = distance;

	// Travel through non-transformed graph
	while (index && MHeap->array[index]->distance < MHeap->array[(index - 1) / 2]->distance)
	{
		// Swaps Node with parent Node
		MHeap->position[MHeap->array[index]->vertex] = (index - 1) / 2;
		MHeap->position[MHeap->array[(index - 1) / 2]->vertex] = index;
		swapMinHeapNode(&MHeap->array[index], &MHeap->array[(index - 1) / 2]);

		// Move to the parent Node
		index = (index - 1) / 2;
	}
}

int isInMinHeap(MinHeap *MHeap, int vertex)
{
	if (MHeap->position[vertex] < MHeap->size)
	{
		return TRUE;
	}

	return FALSE;
}

void printVertexPath(int parent[], int j)
{
	if (parent[j] == -1) // Base case
	{
		return;
	}

	// Print path to Node
	printVertexPath(parent, parent[j]);

	printf("%d ", j);
}

void printVertexData(int distance[], int source, int parent[])
{
	int i = 50; // Vertex source
	printf("Vertex:\t\tDistance from source:\n");
	//for (int i = 0; i < source; i++)
	//{
		printf("%d\t\t\t %d\n", i, distance[i]);
		printf("Path:\t");
		printVertexPath(parent, i);
		printf("\n");
	//}
}

void dijkstrapathfinding(AListGraph *Graph, int source)
{
	// Gets number of vertices and the distance value to pick minimum edge
	int vertex = Graph->vertices;
	int *distance = (int*)malloc(sizeof(int) * vertex);
	int *parent = (int*)malloc(sizeof(int) * vertex);

	MinHeap * MHeap = getMinHeap(vertex);

	// Sets Min Heap for all vertices and all distances values
	for (int v = 0; v < vertex; v++)
	{
		parent[v] = -1;
		distance[v] = INT_MAX;
		MHeap->array[v] = getMinHeapNode(v, distance[v]);
		MHeap->position[v] = v;
	}
	
	// Make distance value of the source vertex to 0 so it gets extracted first
	MHeap->array[source] = getMinHeapNode(source, distance[source]);
	MHeap->position[source] = source;
	distance[source] = 0;
	decreaseKey(MHeap, source, distance[source]);

	// Sets initial size of Min Heap to equal source vertex
	MHeap->size = vertex;

	// Finilize all distances to all nodes...
	while (!minHeapEmpty(MHeap))
	{
		// Extract vertex with minimum distance
		MinHeapNode *MHeapNode = extractMinHeap(MHeap);
		int extract = MHeapNode->vertex;

		// Traverse all neighbors of the extracted vertex and update their distance
		AListNode * Temp = Graph->array[extract].head;
		while (Temp != NULL)
		{
			int v = Temp->dest;
			
			// If shortest distance is not finilized and the distance is less than calculated...
			if ((isInMinHeap(MHeap, v)) && (distance[extract] != INT_MAX) && (Temp->weight + distance[extract] < distance[v]))
			{
				parent[v] = extract;
				distance[v] = distance[extract] + Temp->weight;

				// Update distance in Min Heap
				decreaseKey(MHeap, v, distance[v]);
			}
			
			Temp = Temp->next;
		}
	}

	// Print shortest distances
	printVertexData(distance, vertex, parent);
}

AListGraph * getPathFindingMap()
{
	AListGraph * Graph = createGraph(100);
	// Initialize variables
	int vertices = Graph->vertices, skipahead = 0, skipdown = 0, skipright = 0;
	
	// Initialize lists of inaccessible nodes
	int forbidden[] = { 18, 28, 38, 40, 41, 42, 43, 44, 45, 46, 47, 48, 54, 64, 74, 84 };

	// Go through the entire graph and create the grid
	for (int i = 0; i < vertices; i++)
	{
		// Reset variables
		skipahead = 0;
		skipdown = 0;
		skipright = 0;

		// Check if the Node to be added an edge to is either inaccessible or outside of the grid
		for (int j = 0; j < (sizeof(forbidden) / sizeof(int)); j++)
		{
			if (i == forbidden[j])
			{
				skipahead = 1;
			}
			else if (i + 10 == forbidden[j])
			{
				skipright = 1;
			}
			else if (i + 1 == forbidden[j])
			{
				skipdown = 1;
			}
		}

		if (skipahead == 0) // If the Node is valid...
		{

			if ((i + 10 < vertices) && (skipright == 0)) // If the Node is below...
			{
				addUndirectedEdge(Graph, i, i + 10, 1);
			}

			if (((i + 1) % 10 != 0) && (skipdown == 0)) // If the Node is to the right...
			{
				addUndirectedEdge(Graph, i, i + 1, 1);
			}
		}
	}

	// Use Dijkstra's algorithm to find shortest path and print it
	dijkstrapathfinding(Graph, 0);
}