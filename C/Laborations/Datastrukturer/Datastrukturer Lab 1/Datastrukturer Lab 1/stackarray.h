#pragma once
#define _addtostack_h
#define _readstack_h
#define SIZE 10
#define TRUE 1
#define FALSE 0

int addtostack(int data); // Adds data to top of stack. Returns TRUE if successful, FALSE if unsuccessful

int readstack(); // Returns data at top of stack, returns -999 if stack is empty

int stackArray[SIZE], tracker = -1;