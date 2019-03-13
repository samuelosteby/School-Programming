#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "queuearray.h"
#include "stackarray.h"
#define TRUE 1
#define FALSE 0

// Made by: Samuel Östeby
// Lab 1 in "Datastrukturer och Algoritmer"

int main()
{
	printf("Linked Lists:\n");

	// Create List 1
	List * List1 = NULL;
	List1 = getNewList(List1);

	// Test if List 1 is empty
	if (isEmpty(List1))
	{
		printf("List 1 is empty.\n");
	}

	// Populate List 1 with Nodes
	Node * Node1_1 = NULL;
	Node1_1 = getNewNode(Node1_1, 3);
	Node * Node1_2 = NULL;
	Node1_2 = getNewNode(Node1_2, 1);
	Node * Node1_3 = NULL;
	Node1_3 = getNewNode(Node1_3, 5);
	Node * Node1_4 = NULL;
	Node1_4 = getNewNode(Node1_4, 10);
	Node * Node1_5 = NULL;
	Node1_5 = getNewNode(Node1_5, 8);
	Node * Node1_6 = NULL;
	Node1_6 = getNewNode(Node1_6, 7);

	// Insert Nodes into List
	insert(List1, Node1_1);
	insert(List1, Node1_2);
	insert(List1, Node1_3);
	insert(List1, Node1_4);
	insert(List1, Node1_5);
	insert(List1, Node1_6);

	// Print List 1
	printf("List 1 is: ");
	printList(List1);

	// To test delete: Remove comment markers below...
	//delete(List1, search(List1, 3));
	//delete(List1, search(List1, 10));
	//printf("List 1 is: ");
	//printList(List1);

	// Create List 2
	List * List2 = NULL;
	List2 = getNewList(List2);

	// Test if List 1 is empty
	if (isEmpty(List2))
	{
		printf("List 2 is empty.\n");
	}

	// Populate List 2 with Nodes
	Node * Node2_1 = NULL;
	Node2_1 = getNewNode(Node2_1, 5);
	Node * Node2_2 = NULL;
	Node2_2 = getNewNode(Node2_2, 2);
	Node * Node2_3 = NULL;
	Node2_3 = getNewNode(Node2_3, 9);
	Node * Node2_4 = NULL;
	Node2_4 = getNewNode(Node2_4, 6);
	Node * Node2_5 = NULL;
	Node2_5 = getNewNode(Node2_5, 1);
	Node * Node2_6 = NULL;
	Node2_6 = getNewNode(Node2_6, 2);

	// Insert Nodes into List
	insert(List2, Node2_1);
	insert(List2, Node2_2);
	insert(List2, Node2_3);
	insert(List2, Node2_4);
	insert(List2, Node2_5);
	insert(List2, Node2_6);

	// Print List 2
	printf("List 2 is: ");
	printList(List2);

	printf("Maximums, minimums, successors and predecessors:\n");

	// Find and print maximum numbers in List 1 and 2
	if ((List1 != NULL) && (isEmpty(List1) == FALSE))
	{
		printf("Maximum in List 1: %d\n", maximum(List1)->key);
		printf("Minimum in List 1: %d\n\n", minimum(List1)->key);
	}
	if ((List2 != NULL) && (isEmpty(List2) == FALSE))
	{
		printf("Maximum in List 2: %d\n", maximum(List2)->key);
		printf("Minimum in List 2: %d\n\n", minimum(List2)->key);
	}

	if (successor(List1, search(List1, 5)) != NULL)
	{
		printf("Successor of Node with Key 5 in List 1: %d \n", successor(List1, search(List1, 5))->key);
	}
	else
	{
		printf("There is no successor to Node with Key 5 in List 1:\n");
	}

	if (predecessor(List1, search(List1, 5)))
	{
		printf("Predecessor of Node with Key 5 in List 1: %d \n\n", predecessor(List1, search(List1, 5))->key);
	}
	else
	{
		printf("There is no predecessor to Node with Key 5 in List 1:\n");
	}

	if (successor(List2, search(List2, 9)) != NULL)
	{
		printf("Successor of Node with Key 9 in List 2: %d \n", successor(List2, search(List2, 9))->key);
	}
	else
	{
		printf("There is no successor to Node with Key 9 in List 2\n");
	}

	if (predecessor(List2, search(List2, 9)) != NULL)
	{
		printf("Predecessor of Node with Key 9 in List 2: %d \n\n", predecessor(List2, search(List2, 9))->key);
	}
	else
	{
		printf("There is no predecessor to Node with Key 9 in List 2\n");
	}

	if (predecessor(List2, maximum(List1)) != NULL)
	{
		printf("Predecessor in List 2 of Node with maximum Key in List 1: %d \n", predecessor(List2, maximum(List1))->key);
	}
	else
	{
		printf("There is no predecessor in List 2 of Node with maximum Key in List 1\n");
	}

	if (predecessor(List1, maximum(List2)) != NULL)
	{
		printf("Predecessor in List 1 of Node with maximum Key in List 2: %d \n\n", predecessor(List1, maximum(List2))->key);
	}
	else
	{
		printf("There is no predecessor in List 1 of Node with maximum Key in List 2\n\n");
	}

	printf("Queue:\n");


	QueueArray * queue = NULL;
	queue = createQueue(queue, 10);
	deQueue(queue); // Test if empty queue can be read from
	enQueue(queue, 9);
	enQueue(queue, 6);
	enQueue(queue, 0);
	enQueue(queue, 7);
	enQueue(queue, 1);
	enQueue(queue, 0);
	enQueue(queue, 0);
	enQueue(queue, 1);
	enQueue(queue, 3);
	enQueue(queue, 9);
	enQueue(queue, 1); // This one should say queue is full
	printf("\n");
	printQueue(queue); // To show the full queue before emptying it
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue); // This one should say queue is empty

	printf("\n");
	printf("Stack:\n");

	StackArray * stack = NULL;
	stack = createStack(stack, 10);
	pop(stack); // Test if empty stack can be read from
	push(stack, 9);
	push(stack, 6);
	push(stack, 0);
	push(stack, 7);
	push(stack, 1);
	push(stack, 0);
	push(stack, 0);
	push(stack, 1);
	push(stack, 3);
	push(stack, 9);
	push(stack, 1); // This one should say stack is full
	printf("\n");
	printStack(stack); // To show the full queue before emptying it
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack); //This one should say stack is empty

	printf("\n");
	printf("End of exercises!\n\n");

	system("pause");
}