#include <stdio.h>
#define SIZE 10 // Max size of stack and queue arrays
#define TRUE 1
#define FALSE 0

struct Node // Node to be used in linked list
{
	int key;
	struct Node * next;
	struct Node * prev;
};

int isEmpty(struct Node *L) // Returns true if list L (the sentinel is empty, false otherwise
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

struct Node * getnewList(struct Node *L)
{
	L = (struct Node*)malloc(sizeof(struct Node));
	L->key = 0;
	L->next = L;
	L->prev = L;
	return L;
}

struct Node * getnewNode(int key)
{
	// Create node and allocate memory
	struct Node * NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->key = key;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

int insert(struct Node *L, struct Node *N) // Returns true if node is added to list, false if unsuccessful
{
	if (isEmpty(L) == 1) // If the list is empty...
	{
		L->next = N;
		return TRUE;
	}
	else // If the list isn't empty...
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

	// If we somehow didn't recieve proper values for the function and the insertion fails...
	return FALSE;
}

struct Node * search(struct Node *L, struct Node *N)
{
	if (isEmpty(L) == TRUE) // If the list is empty...
	{
		return NULL;
	}
	else // If the list isn't empty...
	{
		L = L->next;
		while (L != NULL)
		{
			if (L == N) // If N is found...
			{
				return N;
			}
			else // If N isn't the current Node
			{
				// Look at the next Node
				L = L->next;
			}
		}

		// If N isn't in L...
		return NULL;
	}
}

struct Node * delete(struct Node *L, struct Node *N)
{
	struct Node * Dummy;
	if (isEmpty(L) == TRUE) // If the list is empty...
	{
		return NULL; // Can't delete from empty list!
	}
	else if (L->next == N) // If the Node to be deleted is first in the list...
	{
		Dummy = N;
		L->next = L;
		return Dummy;
	}
	else
	{
		L = L->next;
		Dummy = search(L, N);
		if (Dummy == NULL) // If the Node isn't in the list...
		{
			return NULL;
		}
		else // If the Node is in the list...
		{
			Dummy->prev->next = Dummy->next;
			Dummy->next->prev = Dummy->prev;
			free(N);
			return Dummy; // Returns N if it is in the list
		}
	}
}

struct Node * maximum(struct Node *L) // Returns the node containing the biggest key
{
	int i;
	struct Node * Dummy;
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		printf("Maximum problem: Link is empty!\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = L->key;
		Dummy = L;
		L = L->next;

		while (L != NULL)
		{
			if (L->key > i)
			{
				i = L->key;
				Dummy = L;
			}
			L = L->next;
		}

		return Dummy; // pointer to Node containing biggest key
	}
}

struct Node * minimum(struct Node *L) // Returns the node containing the smallest key
{
	int i;
	struct Node * Dummy;
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		return NULL;
	}
	else
	{
		L = L->next;
		i = L->key;
		Dummy = L;
		L = L->next;

		while (L != NULL)
		{
			if (L->key < i)
			{
				i = L->key;
				Dummy = L;
			}
			L = L->next;
		}

		return Dummy; // pointer to Node containing smallest key
	}
}

struct Node * successor(struct Node *L, struct Node *N) // Returns pointer to next node with bigger number
{
	int i;
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		printf("Oh no, the list is empty!\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = N->key;
		while (N != NULL)
		{
			if (N->key > i)
			{
				return N; // Return successor
			}

			N = N->next;
		}

		return NULL; // N was the maximum already
	}
}

struct Node * predecessor(struct Node *L, struct Node *N) // Returns pointer to next node with smaller number
{
	int i;
	if (isEmpty(L) == TRUE) // If List is empty...
	{
		printf("Oh no, the list is empty!\n\n");
		return NULL;
	}
	else
	{
		L = L->next;
		i = N->key;
		while (N != NULL)
		{
			if (N->key < i)
			{
				return N; // Return predecessor
			}

			N = N->next;
		}

		return NULL; // N was the minimum already
	}
}

// Initialize stack array
int stackArray[SIZE], tracker = -1;

int addtostack(int data) // Adds data to top of stack. Returns true if successful, false if unsuccessful
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

int readstack() // Returns data at top of stack
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

// Initialize queue array
int arrayQueue[SIZE], front = -1, rear = -1;

int addtoqueue(int data) // Adds data to end to queue. Returns true if successful, false if unsuccessful
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

int readqueue() // Reads data from start of queue and returns it
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
	// EXERCISE 1:
	printf("Exercise 1:\n");
	// Create first list
	struct Node * List1 = NULL;
	List1 = getnewList(List1);

	if (isEmpty(List1) == TRUE)
	{
		printf("List1 is empty!\n\n");
	}

	struct Node * Node1_1 = getnewNode(3);
	struct Node * Node1_2 = getnewNode(1);
	struct Node * Node1_3 = getnewNode(5);
	struct Node * Node1_4 = getnewNode(10);
	struct Node * Node1_5 = getnewNode(8);
	struct Node * Node1_6 = getnewNode(7);

	//List1 = Node1_1;
	//List1 = insert(List1, Node1_1);
	insert(List1, Node1_1);
	insert(List1, Node1_2);
	insert(List1, Node1_3);
	insert(List1, Node1_4);
	insert(List1, Node1_5);
	insert(List1, Node1_6);

	// AAAAAA List 2
	struct Node * List2 = NULL;
	List2 = getnewList(List2);

	if (isEmpty(List2) == TRUE)
	{
		printf("List2 is empty!\n\n");
	}

	struct Node * Node2_1 = getnewNode(5);
	struct Node * Node2_2 = getnewNode(2);
	struct Node * Node2_3 = getnewNode(9);
	struct Node * Node2_4 = getnewNode(6);
	struct Node * Node2_5 = getnewNode(1);
	struct Node * Node2_6 = getnewNode(2);

	//List1 = Node1_1;
	//List2 = insert(List2, Node2_1);
	insert(List2, Node2_1);
	insert(List2, Node2_2);
	insert(List2, Node2_3);
	insert(List2, Node2_4);
	insert(List2, Node2_5);
	insert(List2, Node2_6);


	// EXERCISE 2:

	printf("Exercise 2:\n");

	struct Node * maximus;
	maximus = maximum(List1);
	printf("%d is the biggest number in List1\n\n", maximus->key);

	struct Node * minimus;
	minimus = minimum(List1);
	printf("%d is the biggest number in List1\n\n", minimus->key);

	maximus = maximum(List2);
	printf("%d is the biggest number in List2\n\n", maximus->key);
	minimus = minimum(List2);
	printf("%d is the biggest number in List2\n\n", minimus->key);

	struct Node * successorus;
	successorus = successor(List1, Node1_3);
	struct Node * predecessorus;
	predecessorus = predecessor(List1, Node1_3);

	if (predecessorus != NULL)
	{
		printf("%d is the successor and %d is the predecessor of Node 3 with key 5 in List1\n\n", successorus->key, predecessorus->key);
	}
	else
	{
		printf("%d is the successor and there is no smaller next node to Node 3 with key 5\n\n", successorus->key);
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
	int i = 0, j = 0;
	struct Node * Teststruct = List1;
	while (Teststruct != maximus)
	{
		i++;
		Teststruct = Teststruct->next;
	}

	struct Node * Teststruct2 = List2;
	for (j = 0; j != i; j++)
	{
		Teststruct2 = Teststruct2->next;
	}

	predecessorus = predecessor(List2, Teststruct2);

	printf("%d is the predecessor in List2 of the maximum of List1\n\n", predecessorus->key);

	maximus = maximum(List2);
	i = 0;
	j = 0;

	Teststruct = List2;
	while (Teststruct != maximus)
	{
		i++;
		Teststruct = Teststruct->next;
	}

	Teststruct2 = List1;
	for (j = 0; j != i; j++)
	{
		Teststruct2 = Teststruct2->next;
	}

	predecessorus = predecessor(List1, Teststruct2);

	if (predecessorus != NULL)
	{
		printf("%d is the predecessor in List1 of the maximum of List2\n\n", predecessorus->key);
	}
	else
	{
		printf("There is no next smaller number in List1 of the maximum of List2\n\n");
	}


	// EXERCISE 3:

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