#pragma once
#define _getnewRoot_h
#define _traverseTreeInOrder_h
#define _traverseTreePreOrder_h
#define _traverseTreePostOrder_h
#define _isEmpty_h
#define _insert_h
#define _search_h
#define _delete_h
#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}TreeNode;

typedef TreeNode Root;

Root * getNewRoot(Root *NewTree, int data); // Creates a new binary tree root and returns it

TreeNode * getNewTreeNode(Root *Tree, int data); // Creates a new tree node, ready to be placed in a binary tree

void traverseTreeInOrder(Root *Tree); // Traverses a binary tree inorder. Use TRUE or FALSE to indicate whether to print values in nodes

void traverseTreePreOrder(Root *Tree); // Traverses a binary tree preorder. Use TRUE or FALSE to indicate whether to print values in nodes

void traverseTreePostOrder(Root *Tree); // Traverses a binary tree postorder. Use TRUE or FALSE to indicate whether to print values in nodes

int isEmpty(Root *Tree); // Returns true if binary tree is empty, false otherwise

TreeNode * insert(Root *Tree, TreeNode *TreeNode); // Inserts a node into a binary tree and returns it, otherwise returns NULL

TreeNode * search(Root *Tree, int data); // Returns a node with the given data if it exists, returns NULL otherwise

TreeNode * delete(Root *Tree, TreeNode *TreeNode); // Deletes the specified node from the binary tree and returns it, returns NULL otherwise