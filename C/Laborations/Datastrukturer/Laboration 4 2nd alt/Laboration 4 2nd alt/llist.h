#pragma once
#define _newList_h
#define _newNode_h
#define _isEmpty_h
#define _insert_h
#define _search_h
#define _delete_h
#define _maximum_h
#define _minimum_h
#define _successor_h
#define _predecessor_h
#define _printList_h

typedef struct Node
{
	int key;
	struct Node * next;
	struct Node * prev;

}Node;

typedef Node List;

List * newList(List *L); // Create and return List

Node * newNode(Node *N, int key); // Create Node with given Key and return it

int isEmpty(List *L); // Check if List is empty. Returns TRUE if empty, FALSE otherwise.

int insert(List *L, Node *N); // Inserts Node into List. Returns TRUE if successful, FALSE otherwise.

Node * search(List *L, int key); // Searches List for Node with Key. Returns Node if successful, otherwise NULL.

Node * delete(List *L, Node *N); // Searches List for Node and deletes it from List. Returns Node if successful, otherwise NULL

Node * maximum(List *L); // Returns Node with the biggest Key.

Node * minimum(List *L); // Returns Node with the smallest Key.

Node * successor(List *L, Node *N); // Returns Node with next biggest Key in List. Returns NULL if no next biggest Node with Key exists

Node * predecessor(List *L, Node *N); // Returns Node with next smallest Key in List. Returns NULL if no next smallest Node with Key exists

void printList(List *L); //Prints all elements in List.