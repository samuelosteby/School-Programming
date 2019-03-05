#pragma once
#define _isempty_h
#define _getnewList_h
#define _getnewNode_h
#define _insert_h
#define _search_h
#define _delete_h
#define _maximum_h
#define _minimum_h
#define _successor_h
#define _predecessor_h
#define _printList_h

typedef struct Node // Node to be used in linked list
{
	int key;
	struct Node * next;
	struct Node * prev;
}Node;

typedef Node List;

int isEmpty(List *L); // Returns TRUE if only the sentinel is in linked list, false otherwise

Node * getnewList(List *L); // Creates new sentinel and returns the node to be used as a head

Node * getnewNode(int key); // Creates a new node with the defined key and returns the node

int insert(List *L, Node *N); // Inserts the node into the list. Returns TRUE if successful, and FALSE if unuccessful

Node * search(List *L, int number); // Searches through a list and returns the node if successfully found, otherwise returns NULL

Node * delete(List *L, Node *N); // Deletes the node from the list and returns the node if successful, otherwise returns NULL

Node * maximum(List *L); // Returns the node with the biggest key in the list. Returns NULL if unsuccessful

Node * minimum(List *L); // Returns the node with the smallest key in the list. Returns NULL if unsuccessful

Node * successor(List *L, Node *N); // Finds the node containing the next biggest key in the list. Returns NULL if unsuccessful

Node * predecessor(List *L, Node *N); // Finds the node containing the next smaller key in the list. Returns NULL if unsuccessful

void printList(List *L);