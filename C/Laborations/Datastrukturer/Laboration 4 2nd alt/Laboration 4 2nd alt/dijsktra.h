#pragma once
#include "graph.h"
#define _newHeapNode_h
#define _newHeap_h
#define _swapHeapNode_h
#define _transformHeap_h
#define _emptyHeap_h
#define _extractHeap_h
#define _lowerDist_h
#define _inHeap_h
#define _printVData_h
#define _dijkstra_h
#define _newPath_h
#define _dijkstraSP_h
#define _printPath_h


HeapNode * newHeapNode(int vertex, int distance); // Creates and returns a min heap node

MinHeap * newHeap(int capacity); // Creates new min heap with a given capacity and returns it

void swapHeapNode(HeapNode **x, HeapNode **y); // Swaps the position of two min heap nodes

void transformHeap(MinHeap *MinHeap, int vertex); // Transforms/Heapifies a given vertex and update position of nodes when they are swapped

int emptyHeap(MinHeap * MinHeap); // Checks if a min heap is empty of not. Returns TRUE if it is, FALSE otherwise

HeapNode * extractHeap(MinHeap *MinHeap); // Extracts the minimum node from a heap and returns it. Returns NULL if heap is empty

void lowerDist(MinHeap *MinHeap, int vertex, int distance); // Decreases distance value of vertex and finds current index of node in min heap

int inHeap(MinHeap *MinHeap, int vertex); // Checks if vertex is in a given min heap. Returns TRUE if it is, FALSE otherwise

void printVData(int distance[], int source, int parent[]); // Prints out the entire path of a given vertex to a given source

void dijsktra(AdjListGraph *Graph, int source, int destination); // Uses Dijkstra's pathfinding algorithm to find shortest path from a source to a given vertex

AdjListGraph * newPath(); // Creates the path finding map needed for exercise 2 and returns it

void dijsktraSP(AdjListGraph *Graph, int source); // Uses Dijkstra's pathfinding algorithm to figure out distances from all vertices to a given source

void printPath(int distance[], int vertices); // Prints out all vertices distance to a source. If the distance is the maximum value of an integer, there's no path