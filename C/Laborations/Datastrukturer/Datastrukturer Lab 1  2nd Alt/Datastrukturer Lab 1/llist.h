#pragma once

#define _newList_h
#define _newNode_h
#define _printList_h
#define _isEmpty_h
#define _insert_h
#define _search_h
#define _delete_h
#define _maximum_h
#define _minimum_h
#define _successor_h
#define _predecessor_h

typedef struct Node
{
	int key;
	struct Node * next;
	struct Node * prev;

}Node;

typedef Node List;

List * newList(List *L); //Creates a list and returns it.

Node * newNode(Node *N, int key); //Creates a node with a key and returns it.

int isEmpty(List *L); //Checks if list is empty, returns TRUE if empty, otherwise FALSE.

void printList(List *L); //Prints list.

int insert(List *L, Node *N); //Inserts node into list, returns TRUE if successfull, otherwise FALSE.

Node * search(List *L, int key); //Search list for node with key. Returns node if successfull otherwise NULL.

Node * delete(List *L, Node *N); //Search list for node and deletes it from list. Returns node if successfull otherwise NULL.

Node * maximum(List *L); //Returns node with the biggest key.

Node * minimum(List *L); //Returns node with the smallest key.

Node * successor(List *L, Node *N); //Returns node with next biggest key in list. Returns NULL if already biggest.

Node * predecessor(List *L, Node *N); //Returns node with next smallest key in list. Returns NULL if already smallest.