#pragma once
#include "linkedlist.h"
#define _newAListNode_h
#define _createGraph_h
#define _addUndirectedEdge_h
#define _printGraph_h
#define _getNumVertices_h
#define _getNumEdges_h
#define _getNeighbors_h
#define _getInNeighbors_h
#define _getOutNeighbors_h
#define _hasEdge_h
#define _getMinHeapNode_h
#define _getMinHeap_h
#define _swapMinHeapNode_h
#define _minHeapTransform_h
#define _minHeapEmpty_h
#define _extractMinHeap_h
#define _decreaseKey_h
#define _isInMinHeap_h
#define _printVertexData_h
#define _dijkstrapathfinding_h
#define _getPathFindingMap_h

typedef struct AListNode
{
	int dest;
	int weight;
	struct AListNode * next;
}AListNode;

typedef struct AList
{
	AListNode * head;
}AList;

typedef struct AListGraph
{
	int vertices;
	AList * array;
}AListGraph;

typedef struct MinHeapNode
{
	int vertex;
	int distance;
}MinHeapNode;

typedef struct MinHeap
{
	int size;
	int capacity;
	int *position;
	MinHeapNode **array;
}MinHeap;

AListNode * getNewAListNode(int dest, int weight); // Creates new adjaceny list node and returns it

AListGraph * createGraph(int vertices); // Creates and returns new adjaceny list graph with a given amount of vertices

void addUndirectedEdge(AListGraph *Graph, int src, int dest, int weight); // Add an undirected edge to graph between source and destination

void addDirectedEdge(AListGraph *Graph, int src, int dest, int weight); // Add a directed edge to graph between source and destination

void printGraph(AListGraph *Graph); // Print the adjaceny list graph

int getNumVertices(AListGraph *Graph); // Returns the amount of vertices in a given adjaceny list graph

int getNumEdges(AListGraph *Graph); // Returns the amount of edges in a given adjaceny list graph

List * getNeighbors(AListGraph *Graph, int vertex); // Returns a list of all vertices connected to a vertex with any kind of edge

List * getInNeighbors(AListGraph *Graph, int vertex); // Returns a list of all vertices ingoing connections to a given vertex

List * getOutNeighbors(AListGraph *Graph, int vertex); // Returns a list of all a given vertex's outgoing connections

int hasEdge(AListGraph *Graph, int vertex1, int vertex2); // Returns TRUE if there's an edge between the two vertices, otherwise returns FALSE

MinHeapNode * getMinHeapNode(int vertex, int distance); // Creates and returns a Min Heap Node

MinHeap * getMinHeap(int capacity); // Creates new Min Heap with a given capacity and returns it

void swapMinHeapNode(MinHeapNode **x, MinHeapNode **y); // Swaps the position of two Min Heap Nodes

void minHeapTransform(MinHeap *MHeap, int vertex); // Transforms/Heapifies a given vertex and update position of nodes when they are swapped

int minHeapEmpty(MinHeap * MHeap); // Checks if a Min Heap is empty of not. Returns TRUE if it is, FALSE otherwise

MinHeapNode * extractMinHeap(MinHeap *MHeap); // Extracts the minimum Node from a Heap and returns it. Returns NULL if Heap is empty

void decreaseKey(MinHeap *MHeap, int vertex, int distance); // Decreases distance value of Vertex and finds current index of Node in Min Heap

int isInMinHeap(MinHeap *MHeap, int vertex); // Checks if vertex is in a given Min Heap. Returns TRUE if it is, FALSE otherwise

void printVertexData(int distance[], int source); // Prints out all a vertices distance to source

void dijkstrapathfinding(AListGraph *Graph, int source); // Uses Dijkstra's pathfinding algorithm to find distance from all vertices to a given source

AListGraph * getPathFindingMap(); // Creates the path finding map needed for exercise 2