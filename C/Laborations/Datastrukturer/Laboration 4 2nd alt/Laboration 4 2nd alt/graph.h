#pragma once
#include "llist.h"
#define _newAdjListNode_h
#define _createGraph_h
#define _addUndirectedEdge_h
#define _addDirectedEdge_h
#define _printGraph_h
#define _getNumVertices_h
#define _getNumEdges_h
#define _getNeighbors_h
#define _getInNeighbors_h
#define _getOutNeighbors_h
#define _hasEdge_h


typedef struct AdjListNode
{
	int destination;
	int weight;
	struct AdjListNode * next;
}AdjListNode;

typedef struct AdjList
{
	AdjListNode * head;
}AdjList;

typedef struct AdjListGraph
{
	int vertices;
	int edges;
	AdjList * array;
}AdjListGraph;

typedef struct HeapNode
{
	int vertex;
	int distance;
}HeapNode;

typedef struct MinHeap
{
	int size;
	int capacity;
	int *position;
	HeapNode **array;
}MinHeap;

typedef struct VStack
{
	int data;
	int capacity;
	int tracker;
	int *array;
}VStack;

AdjListNode * newAdjListNode(int destination, int weight); // Creates new adjaceny list node and returns it

AdjListGraph * createGraph(int vertices); // Creates and returns new adjaceny list graph with a given amount of vertices

void addUndirectedEdge(AdjListGraph * G, int source, int destination, int weight); // Add an undirected edge to graph between source and destination

void addDirectedEdge(AdjListGraph * G, int source, int destination, int weight); // Add a directed edge to graph between source and destination

void printGraph(AdjListGraph * G); // Print an adjaceny list graph

int getNumVertices(AdjListGraph * G); // Returns the amount of vertices in a given adjaceny list graph

int getNumEdges(AdjListGraph * G); // Returns the amount of edges in a given adjaceny list graph

List * getNeighbors(AdjListGraph * G, int vertex); // Returns a list of all vertices connected to a vertex with any kind of edge

List * getInNeighbors(AdjListGraph * G, int vertex); // Returns a list of all vertices ingoing connections to a given vertex

List * getOutNeighbors(AdjListGraph * G, int vertex); // Returns a list of all a given vertex's outgoing connections

int hasEdge(AdjListGraph *G, int vertex1, int vertex2); // Returns TRUE if there's an edge between the two vertices, otherwise returns FALSE


