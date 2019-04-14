#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijsktra.h"
#define TRUE 1
#define FALSE 0
#define INFINITY 9999

HeapNode * newHeapNode(int vertex, int distance)
{
	//Creates new Heap Node.
	HeapNode * NewHeapNode = (HeapNode*)malloc(sizeof(struct HeapNode));
	NewHeapNode->vertex = vertex;
	NewHeapNode->distance = distance;
	return NewHeapNode;
}

MinHeap * newHeap(int capacity)
{
	//Creates new Heap.
	MinHeap *NewHeap = (MinHeap*)malloc(sizeof(MinHeap));
	NewHeap->capacity = capacity;
	NewHeap->position = (int*)malloc(NewHeap->capacity * sizeof(int));
	NewHeap->array = (HeapNode**)malloc(NewHeap->capacity * sizeof(HeapNode*));
	NewHeap->size = 0;
	return NewHeap;
}

void swapHeapNode(HeapNode **a, HeapNode **b)
{
	HeapNode *TempNode = *a;
	*a = *b;
	*b = TempNode;
}

void transformHeap(MinHeap *MinHeap, int vertex)
{
	int smallest = vertex, left = 1 + 2 * vertex, right = 2 + 2 * vertex;

	// Determines where the smallest vertex is
	if ((left < MinHeap->size) && (MinHeap->array[left]->distance < MinHeap->array[smallest]->distance))
	{
		smallest = left;
	}
	if ((right < MinHeap->size) && (MinHeap->array[right]->distance < MinHeap->array[smallest]->distance))
	{
		smallest = right;
	}

	if (smallest != vertex)
	{
		// Creates new nodes to be swapped
		HeapNode *SmallestNode = MinHeap->array[smallest];
		HeapNode *VertexNode = MinHeap->array[vertex];

		// Swaps the positions
		MinHeap->position[SmallestNode->vertex] = vertex;
		MinHeap->position[VertexNode->vertex] = smallest;

		// Swaps the nodes
		swapHeapNode(&MinHeap->array[smallest], &MinHeap->array[vertex]);
		transformHeap(MinHeap, smallest);
	}
}

int emptyHeap(MinHeap * MinHeap)
{
	if (MinHeap->size == 0)
	{
		return TRUE;
	}

	return FALSE;
}

HeapNode * extractHeap(MinHeap *MinHeap)
{
	if (emptyHeap(MinHeap))
	{
		return NULL;
	}
	//Creates base and prev node and puts prev in base.
	HeapNode * prevNode = MinHeap->array[MinHeap->size - 1];
	HeapNode * baseNode = MinHeap->array[0];

	MinHeap->array[0] = prevNode;

	//Sets new postions of prevNode and lowers the size of heap and then transforms the heap.
	MinHeap->position[baseNode->vertex] = MinHeap->size - 1;
	MinHeap->position[prevNode->vertex] = 0;
	--MinHeap->size;
	transformHeap(MinHeap, 0);

	return baseNode;
}

void lowerDist(MinHeap *MinHeap, int vertex, int distance)
{
	//
	// Get the index of vertex in Heap Array and then find the Node to update its distance
	int index = MinHeap->position[vertex];
	MinHeap->array[index]->distance = distance;

	// Travel through non-transformed graph
	while (index && MinHeap->array[index]->distance < MinHeap->array[(index - 1) / 2]->distance)
	{
		// Swaps Node with parent Node
		MinHeap->position[MinHeap->array[index]->vertex] = (index - 1) / 2;
		MinHeap->position[MinHeap->array[(index - 1) / 2]->vertex] = index;
		swapHeapNode(&MinHeap->array[index], &MinHeap->array[(index - 1) / 2]);

		// Move to the parent Node
		index = (index - 1) / 2;
	}
}

int inHeap(MinHeap *MinHeap, int vertex)
{
	if (MinHeap->position[vertex] < MinHeap->size)
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

void printVData(int distance[], int source, int parent[])
{
	printf("Vertex:\t\tDistance from source:\n");
	printf("%d\t\t\t %d\n", source, distance[source]);
	printf("Path:\t");
	printVertexPath(parent, source);
	printf("\n");
}

void dijsktra(AdjListGraph *Graph, int source, int destination)
{
	// Gets number of vertices and the distance value to pick minimum edge
	int vertex = Graph->vertices;
	int *distance = (int*)malloc(sizeof(int) * vertex);
	int *parent = (int*)malloc(sizeof(int) * vertex);

	MinHeap * MinHeap = newHeap(vertex);

	// Sets Min Heap for all vertices and all distances values
	for (int v = 0; v < vertex; v++)
	{
		parent[v] = -1;
		distance[v] = INFINITY;
		MinHeap->array[v] = newHeapNode(v, distance[v]);
		MinHeap->position[v] = v;
	}

	// Make distance value of the source vertex to 0 so it gets extracted first
	MinHeap->array[source] = newHeapNode(source, distance[source]);
	MinHeap->position[source] = source;
	distance[source] = 0;
	lowerDist(MinHeap, source, distance[source]);

	// Sets initial size of Min Heap to equal source vertex
	MinHeap->size = vertex;

	// Finilize all distances to all nodes...
	while (!emptyHeap(MinHeap))
	{
		// Extract vertex with minimum distance
		HeapNode *MHeapNode = extractHeap(MinHeap);
		int extract = MHeapNode->vertex;

		// Traverse all neighbors of the extracted vertex and update their distance
		AdjListNode * Temp = Graph->array[extract].head;
		while (Temp != NULL)
		{
			int v = Temp->destination;

			// If shortest distance is not finilized and the distance is less than calculated...
			if ((inHeap(MinHeap, v)) && (distance[extract] != INFINITY) && (Temp->weight + distance[extract] < distance[v]))
			{
				parent[v] = extract;
				distance[v] = distance[extract] + Temp->weight;

				// Update distance in Min Heap
				lowerDist(MinHeap, v, distance[v]);
			}

			Temp = Temp->next;
		}
	}

	// Print shortest distances
	printVData(distance, destination, parent);
}

AdjListGraph * newPath()
{
	AdjListGraph * Graph = createGraph(100);
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

	return Graph;
}

void dijsktraSP(AdjListGraph *Graph, int source)
{
	// Gets number of vertices and the distance value to pick minimum edge
	int vertex = Graph->vertices;
	int *distance = (int*)malloc(sizeof(int) * vertex);

	MinHeap * MinHeap = newHeap(vertex);

	// Sets Min Heap for all vertices and all distances values
	for (int v = 0; v < vertex; v++)
	{
		distance[v] = INFINITY;
		MinHeap->array[v] = newHeapNode(v, distance[v]);
		MinHeap->position[v] = v;
	}

	// Make distance value of the source vertex to 0 so it gets extracted first
	MinHeap->array[source] = newHeapNode(source, distance[source]);
	MinHeap->position[source] = source;
	distance[source] = 0;
	lowerDist(MinHeap, source, distance[source]);

	// Sets initial size of Min Heap to equal source vertex
	MinHeap->size = vertex;

	// Finilize all distances to all nodes...
	while (!emptyHeap(MinHeap))
	{
		// Extract vertex with minimum distance
		HeapNode *MHeapNode = extractHeap(MinHeap);
		int extract = MHeapNode->vertex;

		// Traverse all neighbors of the extracted vertex and update their distance
		AdjListNode * Temp = Graph->array[extract].head;
		while (Temp != NULL)
		{
			int v = Temp->destination;

			// If shortest distance is not finilized and the distance is less than calculated...
			if ((inHeap(MinHeap, v)) && (distance[extract] != INFINITY) && (Temp->weight + distance[extract] < distance[v]))
			{
				distance[v] = distance[extract] + Temp->weight;

				// Update distance in Min Heap
				lowerDist(MinHeap, v, distance[v]);
			}

			Temp = Temp->next;
		}
	}

	// Print shortest distances
	printPath(distance, vertex);
}

void printPath(int distance[], int vertices)
{
	// Check whether the distance is the maximum of an integer. If it is, there's no path, otherwise print it
	for (int i = 0; i < vertices; i++)
	{
		if (distance[i] == INFINITY)
		{
			printf("Vertex id: %d \t\t  There is no path from source\n", i);
		}
		else
		{
			printf("Vertex id: %d \t\t  Distance is: %d\n", i, distance[i]);
		}
	}
}