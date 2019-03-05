#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "queuearray.h"
#include "stackarray.h"
#define TRUE 1
#define FALSE 0

// CREATED BY: Samuel Östeby

int main()
{
	// EXERCISE 1:
	printf("Exercise 1:\n");

	// Create first list
	List * List1 = NULL;
	List1 = getnewList(List1);

	if (isEmpty(List1) == TRUE)
	{
		printf("List1 is empty!\n\n");
	}

	Node * Node1_1 = getnewNode(3);
	Node * Node1_2 = getnewNode(1);
	Node * Node1_3 = getnewNode(5);
	Node * Node1_4 = getnewNode(10);
	Node * Node1_5 = getnewNode(8);
	Node * Node1_6 = getnewNode(7);

	insert(List1, Node1_1);
	insert(List1, Node1_2);
	insert(List1, Node1_3);
	insert(List1, Node1_4);
	insert(List1, Node1_5);
	insert(List1, Node1_6);

	printf("List1: ");
	printList(List1);

	//TO DELETE, REMOVE COMMENT SYMBOLS BELOW:
	//delete(List1, search(List1, 5));
	//printf("List1: ");
	//printList(List1);

	// Create second list
	List * List2 = NULL;
	List2 = getnewList(List2);

	if (isEmpty(List2) == TRUE)
	{
		printf("List2 is empty!\n\n");
	}

	Node * Node2_1 = getnewNode(5);
	Node * Node2_2 = getnewNode(2);
	Node * Node2_3 = getnewNode(9);
	Node * Node2_4 = getnewNode(6);
	Node * Node2_5 = getnewNode(1);
	Node * Node2_6 = getnewNode(2);

	insert(List2, Node2_1);
	insert(List2, Node2_2);
	insert(List2, Node2_3);
	insert(List2, Node2_4);
	insert(List2, Node2_5);
	insert(List2, Node2_6);

	printf("List2: ");
	printList(List2);

	// EXERCISE 2:

	printf("Exercise 2:\n");

	Node * maximus;
	maximus = maximum(List1);
	printf("%d is the biggest number in List1\n\n", maximus->key);

	Node * minimus;
	minimus = minimum(List1);
	printf("%d is the smallest number in List1\n\n", minimus->key);

	maximus = maximum(List2);
	printf("%d is the biggest number in List2\n\n", maximus->key);
	minimus = minimum(List2);
	printf("%d is the smallest number in List2\n\n", minimus->key);

	Node * successorus;
	successorus = successor(List1, Node1_3);
	Node * predecessorus;
	predecessorus = predecessor(List1, Node1_3);

	if (predecessorus != NULL)
	{
		printf("%d is the successor and %d is the predecessor of Node 3 with key 5 in List1\n\n", successorus->key, predecessorus->key);
	}
	else
	{
		printf("%d is the successor and there is no smaller next node to Node 3 with key 5 in List2\n\n", successorus->key);
	}

	successorus = successor(List2, Node2_3);
	predecessorus = predecessor(List2, Node2_3);

	if (successorus != NULL)
	{
		printf("%d is the successor and %d is the predecessor of Node 3 with key 9 in List1\n\n", successorus->key, predecessorus->key);
	}
	else
	{
		printf("%d is the predecessor and there is no bigger next node to Node 3 with key 9\n\n", predecessorus->key);
	}

	maximus = maximum(List1);
	Node * Crossoverpred = getnewNode(maximus->key);
	Crossoverpred = predecessor(List2, Crossoverpred);

	printf("%d is the predecessor in List2 of the maximum of List1\n\n", Crossoverpred->key);

	maximus = maximum(List2);
	Crossoverpred = getnewNode(maximus->key);
	Crossoverpred = predecessor(List1, Crossoverpred);

	printf("%d is the predecessor in List1 of the maximum of List2\n\n", Crossoverpred->key);


	// EXERCISE 3:
	printf("Exercise 3:");
	Queue_array * Queue = NULL;
	Queue = getnewQueue(Queue, 10);

	Stack_array * Stack = NULL;
	Stack = getnewStack(Stack, 10);

	printf("\nTesting queue!\n\n");

	dequeue(Queue);
	enqueue(Queue, 9);
	enqueue(Queue, 6);
	enqueue(Queue, 0);
	enqueue(Queue, 7);
	enqueue(Queue, 1);
	enqueue(Queue, 0);
	enqueue(Queue, 0);
	enqueue(Queue, 1);
	enqueue(Queue, 3);
	enqueue(Queue, 9);
	enqueue(Queue, 1);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);
	dequeue(Queue);

	printf("\nTesting Stack!\n\n");
	popStack(Stack);
	pushStack(Stack, 9);
	pushStack(Stack, 6);
	pushStack(Stack, 0);
	pushStack(Stack, 7);
	pushStack(Stack, 1);
	pushStack(Stack, 0);
	pushStack(Stack, 0);
	pushStack(Stack, 1);
	pushStack(Stack, 3);
	pushStack(Stack, 9);
	pushStack(Stack, 1);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);
	popStack(Stack);

	system("pause");
}