#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10 //maximum size of stack

// IN PROGRESS

struct Node //node struct
{
	int data;
	struct Node * next;
	struct Node * prev;
};

int isEmpty(struct Node *L) //true if successful, false if unsuccessful
{
	if (L->next == L)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

struct Node * NewList(struct Node *L) //returns new list 
{
	L = (struct Node*)malloc(sizeof(struct Node));
	L->data = 999;
	L->next = L;
	L->prev = L;
	return L;
}

struct Node * getnewNode(int data)
{
	//create node
	struct Node * NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

int insert(struct Node *L, struct Node *N) //true if successful, false if unsuccessful
{
	if (isEmpty(L) == 1)
	{
		L->next = N;
		return TRUE;
	}
	else
	{
		L = L->next;
		while (L->next != NULL)
		{
			L = L->next;
		}

		L->next = N;
		N->prev = L;
		return TRUE;
	}

	return FALSE;
}

struct Node * search(struct Node *L, struct Node *N) //finds node and returns it
{
	if (isEmpty(L) == TRUE)
	{
		return NULL;
	}
	else
	{
		L = L->next;
		while (L != NULL)
		{
			if (L == N)
			{
				return N;
			}
			else
			{
				L = L->next;
			}
		}
		return NULL;
	}
}

struct Node * delete(struct Node *L, struct Node *N) //returns deleted node after deletion
{
	struct Node * Test;
	if (isEmpty(L) == TRUE)
	{
		return NULL;
	}
	else if (L->next == N)
	{
		L->next = L;
		return N;
	}
	else
	{
		L = L->next;
		Test = search(L, N);
		if (Test == NULL)
		{
			return NULL;
		}
		else
		{
			Test->prev->next = Test->next;
			Test->next->prev = Test->prev;
			return Test;
		}
	}
}

struct Node * maximum(struct Node *L) //returns biggest data node
{
	int i;
	struct Node * Test;
	if (isEmpty(L) == TRUE)
	{
		printf("Maximum problem: Link is empty!\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = L->data;
		Test = L;
		L = L->next;

		while (L != NULL)
		{
			if (L->data > i)
			{
				i = L->data;
				Test = L;
			}
			L = L->next;
		}

		return Test; // pointer to Node containing biggest data
	}
}

struct Node * minimum(struct Node *L) //returns smallest node
{
	int i;
	struct Node * Test;
	if (isEmpty(L) == TRUE)
	{
		return NULL;
	}
	else
	{
		L = L->next;
		i = L->data;
		Test = L;
		L = L->next;

		while (L != NULL)
		{
			if (L->data < i)
			{
				i = L->data;
				Test = L;
			}
			L = L->next;
		}

		return Test;
	}
}

struct Node * successor(struct Node *L, struct Node *N) //returns next node with biggest data number
{
	int i;
	if (isEmpty(L) == TRUE)
	{
		printf("Oh no, the list is empty!\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = N->data;
		while (N != NULL)
		{
			if (N->data > i)
			{
				return N;
			}

			N = N->next;
		}

		return NULL;
	}
}

struct Node * predecessor(struct Node *L, struct Node *N) //returns next node with smaller data number
{
	int i;
	if (isEmpty(L) == TRUE)
	{
		printf("Oh no, the list is empty!\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = N->data;
		while (N != NULL)
		{
			if (N->data < i)
			{
				return N;
			}

			N = N->next;
		}

		return NULL;
	}
}

int stackArray[SIZE], tracker = -1;

int addtostack(int data) //adds to stack. True if successful, false if unsuccessful
{
	if (tracker == -1)
	{
		tracker = 0;
		stackArray[0] = data;
		printf("%d was added to stack!\n\n", data);
		return TRUE;
	}
	else if (tracker == SIZE - 1)
	{
		printf("Stack is full!\n\n");
		return FALSE;
	}
	else
	{
		tracker++;
		stackArray[tracker] = data;
		printf("%d was added to stack!\n\n", data);
		return TRUE;
	}
}

int readstack() //returns top of stack
{
	int result, i;

	if (tracker == -1)
	{
		printf("Stack is empty!\n\n");
	}
	else
	{
		result = stackArray[tracker];
		tracker--;
		printf("Returning %d\n\n", result);
		return result;
	}
}

int arrayQueue[SIZE], front = -1, rear = -1;

int addtoqueue(int data) //adds data to queue. True if successful, false if unsuccessful
{
	if (rear == SIZE - 1)
	{
		printf("Queue is full!\n\n");
		return FALSE;
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}

		rear++;
		arrayQueue[rear] = data;
		printf("Added %d to queue!\n\n", data);
		return TRUE;
	}
}

int readqueue() //reads start of queue
{
	int result, i;
	if (front == -1)
	{
		printf("The queue is empty!\n\n");
	}
	else
	{
		result = arrayQueue[0];

		for (i = 0; i < rear; i++)
		{
			arrayQueue[i] = arrayQueue[i + 1];
		}

		rear--;

		if (rear == -1)
		{
			front = -1;
		}

		printf("Returning %d\n\n", result);
		return result;
	}
}

int main()
{
	printf("Exercise 1:\n");

	struct Node * list1 = NULL;
	list1 = getnewList(list1);

	if (isEmpty(list1) == TRUE)
	{
		printf("list1 is empty!\n\n");
	}

	struct Node * Node1_1 = getnewNode(3);
	struct Node * Node1_2 = getnewNode(1);
	struct Node * Node1_3 = getnewNode(5);
	struct Node * Node1_4 = getnewNode(10);
	struct Node * Node1_5 = getnewNode(8);
	struct Node * Node1_6 = getnewNode(7);

	insert(list1, Node1_1);
	insert(list1, Node1_2);
	insert(list1, Node1_3);
	insert(list1, Node1_4);
	insert(list1, Node1_5);
	insert(list1, Node1_6);

	struct Node * list2 = NULL;
	list2 = getnewList(list2);

	if (isEmpty(list2) == TRUE)
	{
		printf("list2 is empty!\n\n");
	}

	struct Node * Node2_1 = getnewNode(5);
	struct Node * Node2_2 = getnewNode(2);
	struct Node * Node2_3 = getnewNode(9);
	struct Node * Node2_4 = getnewNode(6);
	struct Node * Node2_5 = getnewNode(1);
	struct Node * Node2_6 = getnewNode(2);

	insert(list2, Node2_1);
	insert(list2, Node2_2);
	insert(list2, Node2_3);
	insert(list2, Node2_4);
	insert(list2, Node2_5);
	insert(list2, Node2_6);

	printf("Exercise 2:\n");

	struct Node * maximus;
	maximus = maximum(list1);
	printf("%d is the biggest number in list1\n\n", maximus->data);

	struct Node * minimus;
	minimus = minimum(list1);
	printf("%d is the biggest number in list1\n\n", minimus->data);

	maximus = maximum(list2);
	printf("%d is the biggest number in list2\n\n", maximus->data);
	minimus = minimum(list2);
	printf("%d is the biggest number in list2\n\n", minimus->data);

	struct Node * successorus;
	successorus = successor(list1, Node1_3);
	struct Node * predecessorus;
	predecessorus = predecessor(list1, Node1_3);

	if (predecessorus != NULL)
	{
		printf("%d is the successor and %d is the predecessor of Node 3 with data 5 in list1\n\n", successorus->data, predecessorus->data);
	}
	else
	{
		printf("%d is the successor and there is no smaller next node to Node 3 with data 5\n\n", successorus->data);
	}

	successorus = successor(list2, Node2_3);
	predecessorus = predecessor(list2, Node2_3);

	if (successorus != NULL)
	{
		printf("%d is the successor and %d is the predecessor of Node 3 with data 9 in list1\n\n", successorus->data, predecessorus->data);
	}
	else
	{
		printf("%d is the predecessor and there is no bigger next node to Node 3 with data 9\n\n", predecessorus->data);
	}

	maximus = maximum(list1);
	int i = 0, j = 0;
	struct Node * Teststruct = list1;
	while (Teststruct != maximus)
	{
		i++;
		Teststruct = Teststruct->next;
	}

	struct Node * Teststruct2 = list2;
	for (j = 0; j != i; j++)
	{
		Teststruct2 = Teststruct2->next;
	}

	predecessorus = predecessor(list2, Teststruct2);

	printf("%d is the predecessor in list2 of the maximum of list1\n\n", predecessorus->data);

	maximus = maximum(list2);
	i = 0;
	j = 0;

	Teststruct = list2;
	while (Teststruct != maximus)
	{
		i++;
		Teststruct = Teststruct->next;
	}

	Teststruct2 = list1;
	for (j = 0; j != i; j++)
	{
		Teststruct2 = Teststruct2->next;
	}

	predecessorus = predecessor(list1, Teststruct2);

	if (predecessorus != NULL)
	{
		printf("%d is the predecessor in list1 of the maximum of list2\n\n", predecessorus->data);
	}
	else
	{
		printf("There is no next smaller number in list1 of the maximum of list2\n\n");
	}

	addtostack(9);
	addtostack(6);
	addtostack(0);
	addtostack(7);
	addtostack(1);
	addtostack(0);
	addtostack(0);
	addtostack(1);
	addtostack(3);
	addtostack(9);
	addtostack(1);
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();
	readstack();

	addtoqueue(9);
	addtoqueue(6);
	addtoqueue(0);
	addtoqueue(7);
	addtoqueue(1);
	addtoqueue(0);
	addtoqueue(0);
	addtoqueue(1);
	addtoqueue(3);
	addtoqueue(9);
	addtoqueue(1);
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();
	readqueue();

	system("pause");
}