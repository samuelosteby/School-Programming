#pragma once
#include "graph.h"
#define _DFS_h
#define _transposeGraph_h
#define _newStack_h
#define _emptyStack_h
#define _pushStack_h
#define _popStack_h
#define _fillStack_h
#define _printSCC_h


void DFS(AdjListGraph *Graph, int vertex, int visited[]); // Recursively prints a Depth First Search starting from a given vertex

AdjListGraph * transposeGraph(AdjListGraph *Graph); // Creates a transposed version (all edges flipped) of a given graph and returns it

VStack * newStack(int capacity); // Create and return new stack to be used for DFS

int emptyStack(VStack *Stack); // Returns TRUE if stack if empty, FALSE otherwise

void pushStack(VStack *Stack, int data); // Pushes a given data into a given stack

int popStack(VStack *Stack); // Pops a stack and returns the data

void fillStack(AdjListGraph *Graph, int vertex, int visited[], VStack *Stack); // Fills a stack with vertices from a graph based on finishing time

void printSCC(AdjListGraph *Graph); // Prints out all strongly connected components in a given graph
