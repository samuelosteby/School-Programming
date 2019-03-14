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

typedef struct AListNode
{
	int data;
	int dest;
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

AListNode * getNewAListNode(int dest); // Creates new adjaceny list node and returns it

AListGraph * createGraph(int vertices); // Creates and returns new adjaceny list graph with a given amount of vertices

void addUndirectedEdge(AListGraph *Graph, int src, int dest); // Add an undirected edge to graph between source and destination

void addDirectedEdge(AListGraph *Graph, int src, int dest); // Add a directed edge to graph between source and destination

void printGraph(AListGraph *Graph); // Print the adjaceny list graph

int getNumVertices(AListGraph *Graph); // Returns the amount of vertices in a given adjaceny list graph

int getNumEdges(AListGraph *Graph); // Returns the amount of edges in a given adjaceny list graph

List * getNeighbors(AListGraph *Graph, int vertex); // Returns a list of all vertices connected to a vertex with any kind of edge

List * getInNeighbors(AListGraph *Graph, int vertex); // Returns a list of all vertices ingoing connections to a given vertex

List * getOutNeighbors(AListGraph *Graph, int vertex); // Returns a list of all a given vertex's outgoing connections

int hasEdge(AListGraph *Graph, int vertex1, int vertex2); // Returns TRUE if there's an edge between the two vertices, otherwise returns FALSE