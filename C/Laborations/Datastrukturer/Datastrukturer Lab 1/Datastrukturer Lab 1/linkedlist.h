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

struct Node // Node to be used in linked list
{
	int key;
	struct Node * next;
	struct Node * prev;
};

int isEmpty(struct Node *L); // Returns TRUE if only the sentinel is in linked list, false otherwise

struct Node * getnewList(struct Node *L); // Creates new sentinel and returns the node to be used as a head

struct Node * getnewNode(int key); // Creates a new node with the defined key and returns the node

int insert(struct Node *L, struct Node *N); // Inserts the node into the list. Returns TRUE if successful, and FALSE if unuccessful

struct Node * search(struct Node *L, struct Node *N); // Searches through a list and returns the node if successfully found, otherwise returns NULL

struct Node * delete(struct Node *L, struct Node *N); // Deletes the node from the list and returns the node if successful, otherwise returns NULL

struct Node * maximum(struct Node *L); // Returns the node with the biggest key in the list. Returns NULL if unsuccessful

struct Node * minimum(struct Node *L); // Returns the node with the smallest key in the list. Returns NULL if unsuccessful

struct Node * successor(struct Node *L, struct Node *N); // Finds the node containing the next biggest key in the list. Returns NULL if unsuccessful

struct Node * predecessor(struct Node *L, struct Node *N); // Finds the node containing the next smaller key in the list. Returns NULL if unsuccessful