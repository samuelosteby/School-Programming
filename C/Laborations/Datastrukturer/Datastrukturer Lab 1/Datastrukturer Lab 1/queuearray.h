#pragma once
#define _createQueue_h
#define _printQueue_h
#define _enQueue_h
#define _deQueue_h

typedef struct QueueArray
{
	int *data;
	int size;
	int front;
	int rear;

}QueueArray;

QueueArray * createQueue(QueueArray *Queue, int size); // Creates queue with given size and returns it

void printQueue(QueueArray *Queue); // Prints queue

void enQueue(QueueArray *Queue, int data); // Inserts data into queue

int deQueue(QueueArray *Queue); //Returns first element in queue, otherwise returns -99999