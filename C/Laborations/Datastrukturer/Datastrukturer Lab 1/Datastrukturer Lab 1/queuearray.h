#pragma once
#define _addtoqueue_h
#define _readqueue_h
#define SIZE 10
#define TRUE 1
#define FALSE 0

int addtoqueue(int data); // Adds data to end to queue. Returns TRUE if successful, FALSE if unsuccessful

int readqueue(); // Reads data from start of queue and returns it, returns -999 if queue is empty

int arrayQueue[SIZE], front = -1, rear = -1;