#pragma once
#define _getnewQueue_h
#define _enqueue_h
#define _dequeue_h
#define _printQueue_h
#define TRUE 1
#define FALSE 0

typedef struct Queue_array // Node to be used in linked list
{
	int size;
	int *data;
	int front;
	int rear;
}Queue_array;

Queue_array * getnewQueue(Queue_array *Queue, int size); // Creates new Queue

int enqueue(Queue_array *Queue, int data); // Adds data to end to queue. Returns TRUE if successful, FALSE if unsuccessful

int dequeue(Queue_array *Queue); // Reads data from start of queue and returns it, returns -999 if queue is empty

void printQueue(Queue_array *Queue);