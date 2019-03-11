#pragma once
#define _createQueue_h
#define _printQueue_h
#define _enQueue_h
#define _deQueue_h

typedef struct Queue
{
	int *data;
	int size;
	int head;
	int rear;

}Queue;

Queue * createQueue(Queue *Q, int size); //Creates queue with input size and returns it.

void printQueue(Queue *Q); //Prints queue.

void enQueue(Queue *Q, int data); //Inserts data into next available place in queue.

int deQueue(Queue *Q); //Returns first element in queue otherwise returns -1337.

