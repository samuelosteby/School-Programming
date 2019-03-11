// MADE BY: Hampus Tuokkola

#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "queue.h"
#include "stack.h"
#define TRUE 1
#define FALSE 0


int main()
{

	printf("Exercise 2.\n\n");

	List * List1 = NULL;
	List1 = newList(List1);
	if (isEmpty(List1))
	{
		printf("List 1 is empty.\n");
	}
	Node * Node1_1 = NULL;
	Node1_1 = newNode(Node1_1, 3);
	Node * Node1_2 = NULL;
	Node1_2 = newNode(Node1_2, 1);
	Node * Node1_3 = NULL;
	Node1_3 = newNode(Node1_3, 5);
	Node * Node1_4 = NULL;
	Node1_4 = newNode(Node1_4, 10);
	Node * Node1_5 = NULL;
	Node1_5 = newNode(Node1_5, 8);
	Node * Node1_6 = NULL;
	Node1_6 = newNode(Node1_6, 7);
	insert(List1, Node1_1);
	insert(List1, Node1_2);
	insert(List1, Node1_3);
	insert(List1, Node1_4);
	insert(List1, Node1_5);
	insert(List1, Node1_6);
	printf("List 1 is: ");
	printList(List1);

	//!!!!Test for delete!!!!
	//delete(List1, search(List1, 5));
	//printf("List 1 is: ");
	//printList(List1);
	//!!!!!!!!!!!!!!!!!!!!!!!

	List * List2 = NULL;
	List2 = newList(List2);
	if (isEmpty(List2))
	{
		printf("List 2 is empty.\n");
	}
	Node * Node2_1 = NULL;
	Node2_1 = newNode(Node2_1, 5);
	Node * Node2_2 = NULL;
	Node2_2 = newNode(Node2_2, 2);
	Node * Node2_3 = NULL;
	Node2_3 = newNode(Node2_3, 9);
	Node * Node2_4 = NULL;
	Node2_4 = newNode(Node2_4, 6);
	Node * Node2_5 = NULL;
	Node2_5 = newNode(Node2_5, 1);
	Node * Node2_6 = NULL;
	Node2_6 = newNode(Node2_6, 2);
	insert(List2, Node2_1);
	insert(List2, Node2_2);
	insert(List2, Node2_3);
	insert(List2, Node2_4);
	insert(List2, Node2_5);
	insert(List2, Node2_6);
	printf("List 2 is: ");
	printList(List2);

	printf("Maximum in L1: %d\n", maximum(List1)->key);
	printf("Minimum in L1: %d\n\n", minimum(List1)->key);
	printf("Maximum in L2: %d\n", maximum(List2)->key);
	printf("Minimum in L2: %d\n\n", minimum(List2)->key);

	printf("Successor of Node with Key 5 in L1 is: %d \n", successor(List1, search(List1, 5))->key);
	printf("Predecessor of Node with Key 5 in L1 is: %d \n\n", predecessor(List1, search(List1, 5))->key);

	if (successor(List2, search(List2, 9)) == NULL)
	{
		printf("There is no sucessor to the node with key 9 in L2\n");
	}
	else
	{
	printf("Successor of Node with Key 9 in L2 is: %d \n", successor(List2, search(List2, 9))->key);
	}
	printf("Predecessor of Node with Key 9 in L2 is: %d \n\n", predecessor(List2, search(List2, 9))->key);

	printf("Predecessor in L2 off node with maximum Key in L1 is: %d \n", predecessor(List2, maximum(List1))->key);
	printf("Predecessor in L1 off node with maximum Key in L2 is: %d \n\n", predecessor(List1, maximum(List2))->key);

	printf("Exercise 5.\n");


	Queue * queue = NULL;
	queue = createQueue(queue, 10);

	deQueue(queue);
	enQueue(queue, 9);
	enQueue(queue, 6);
	enQueue(queue, 0);
	enQueue(queue, 3);
	enQueue(queue, 2);
	enQueue(queue, 6);
	enQueue(queue, 7);
	enQueue(queue, 7);
	enQueue(queue, 5);
	enQueue(queue, 9);
	enQueue(queue, 1);
	deQueue(queue);
	enQueue(queue, 1);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);

	printf("\n\n");


	Stack * stack = NULL;
	stack = createStack(stack, 10);


	pop(stack);
	push(stack, 9);
	push(stack, 6);
	push(stack, 0);
	push(stack, 3);
	push(stack, 2);
	push(stack, 6);
	push(stack, 7);
	push(stack, 7);
	push(stack, 5);
	push(stack, 9);
	push(stack, 9);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	push(stack, 7);
	pop(stack);
	pop(stack);

	system("pause");
}