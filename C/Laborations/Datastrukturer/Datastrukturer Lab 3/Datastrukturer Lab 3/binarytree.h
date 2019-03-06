#pragma once
#define _getnewRoot_h
#define _traverseTreeInOrder_h
#define _traverseTreePreOrder_h
#define _traverseTreePostOrder_h
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

void traverseTreeInOrder(Root *Tree, int print); // Traverses a binary tree inorder. Use TRUE or FALSE to indicate whether to print values in nodes

void traverseTreePreOrder(Root *Tree, int print); // Traverses a binary tree preorder. Use TRUE or FALSE to indicate whether to print values in nodes

void traverseTreePostOrder(Root *Tree, int print); // Traverses a binary tree postorder. Use TRUE or FALSE to indicate whether to print values in nodes