#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#define TRUE 1
#define FALSE 0

int main()
{
	// EXERCISE 1
	printf("Exercise 1:\n\n");

	// Create binary tree root...
	Root * TreeRoot = NULL;

	if (isEmpty(TreeRoot))
	{
		printf("Tree is empty!\n\n");
	}

	TreeRoot = getNewRoot(TreeRoot, 10);

	// Fill out rest of tree with nodes...
	TreeNode * Node1 = NULL;
	TreeNode * Node2 = NULL;
	TreeNode * Node3 = NULL;
	TreeNode * Node4 = NULL;
	TreeNode * Node5 = NULL;
	
	Node1 = getNewTreeNode(Node1, 8);
	Node2 = getNewTreeNode(Node2, 6);
	Node3 = getNewTreeNode(Node3, 9);
	Node4 = getNewTreeNode(Node4, 20);
	Node5 = getNewTreeNode(Node5, 15);
	
	
	insert(TreeRoot, Node1);
	insert(TreeRoot, Node2);
	insert(TreeRoot, Node3);
	insert(TreeRoot, Node4);
	insert(TreeRoot, Node5);

	// Print out values in binary tree
	printf("The tree traversed inorder: ");
	traverseTreeInOrder(TreeRoot);
	printf("\n\n");

	printf("The tree traversed preorder: ");
	traverseTreePreOrder(TreeRoot);
	printf("\n\n");

	printf("The tree traversed postorder: ");
	traverseTreePostOrder(TreeRoot);
	printf("\n\n");

	// Search for a given node
	TreeNode * Test = NULL;
	Test = search(TreeRoot, 9);
	if (!isEmpty(Test))
	{
		printf("Test: %d\n\n", Test->data);
	}
	else
	{
		printf("No such node exists!\n\n");
	}

	system("pause");
}