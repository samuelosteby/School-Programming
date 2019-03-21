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
#define _dijkstrashortestpath_h
#define _printVertexPaths_h
#define _depthFirstSearch_h
#define _transposeGraph_h
#define _createGraphStack_h
#define _IsEmptyStack_h
#define _pushGraphStack_h
#define _popGraphStack_h
#define _fillOrder_h
#define _printStronglyCC_h

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
	int edges;
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

typedef struct GraphStack
{
	int data;
	int capacity;
	int tracker;
	int *array;
}GraphStack;

AListNode * getNewAListNode(int dest, int weight); // Creates new adjaceny list node and returns it

AListGraph * createGraph(int vertices); // Creates and returns new adjaceny list graph with a given amount of vertices

void addUndirectedEdge(AListGraph *Graph, int src, int dest, int weight); // Add an undirected edge to graph between source and destination

void addDirectedEdge(AListGraph *Graph, int src, int dest, int weight); // Add a directed edge to graph between source and destination

void printGraph(AListGraph *Graph); // Print an adjaceny list graph

int getNumVertices(AListGraph *Graph); // Returns the amount of vertices in a given adjaceny list graph

int getNumEdges(AListGraph *Graph); // Returns the amount of edges in a given adjaceny list graph

List * getNeighbors(AListGraph *Graph, int vertex); // Returns a list of all vertices connected to a vertex with any kind of edge

List * getInNeighbors(AListGraph *Graph, int vertex); // Returns a list of all vertices ingoing connections to a given vertex

List * getOutNeighbors(AListGraph *Graph, int vertex); // Returns a list of all a given vertex's outgoing connections

int hasEdge(AListGraph *Graph, int vertex1, int vertex2); // Returns TRUE if there's an edge between the two vertices, otherwise returns FALSE

MinHeapNode * getMinHeapNode(int vertex, int distance); // Creates and returns a min heap node

MinHeap * getMinHeap(int capacity); // Creates new min heap with a given capacity and returns it

void swapMinHeapNode(MinHeapNode **x, MinHeapNode **y); // Swaps the position of two min heap nodes

void minHeapTransform(MinHeap *MHeap, int vertex); // Transforms/Heapifies a given vertex and update position of nodes when they are swapped

int minHeapEmpty(MinHeap * MHeap); // Checks if a min heap is empty of not. Returns TRUE if it is, FALSE otherwise

MinHeapNode * extractMinHeap(MinHeap *MHeap); // Extracts the minimum node from a heap and returns it. Returns NULL if heap is empty

void decreaseKey(MinHeap *MHeap, int vertex, int distance); // Decreases distance value of vertex and finds current index of node in min heap

int isInMinHeap(MinHeap *MHeap, int vertex); // Checks if vertex is in a given min heap. Returns TRUE if it is, FALSE otherwise

void printVertexData(int distance[], int source, int parent[]); // Prints out the entire path of a given vertex to a given source

void dijkstrapathfinding(AListGraph *Graph, int source, int destination); // Uses Dijkstra's pathfinding algorithm to find shortest path from a source to a given vertex

AListGraph * getPathFindingMap(); // Creates the path finding map needed for exercise 2 and returns it

void dijkstrashortestpath(AListGraph *Graph, int source); // Uses Dijkstra's pathfinding algorithm to figure out distances from all vertices to a given source

void printVertexPaths(int distance[], int vertices); // Prints out all vertices distance to a source. If the distance is the maximum value of an integer, there's no path

void depthFirstSearch(AListGraph *Graph, int vertex, int visited[]); // Recursively prints a Depth First Search starting from a given vertex

AListGraph * transposeGraph(AListGraph *Graph); // Creates a transposed version (all edges flipped) of a given graph and returns it

GraphStack * createGraphStack(int capacity); // Create and return new stack to be used for DFS

int IsEmptyStack(GraphStack *Stack); // Returns TRUE if stack if empty, FALSE otherwise

void pushGraphStack(GraphStack *Stack, int data); // Pushes a given data into a given stack

int popGraphStack(GraphStack *Stack); // Pops a stack and returns the data

void fillOrder(AListGraph *Graph, int vertex, int visited[], GraphStack *Stack); // Fills a stack with vertices from a graph based on finishing time

void printStronglyCC(AListGraph *Graph); // Prints out all strongly connected components in a given graph