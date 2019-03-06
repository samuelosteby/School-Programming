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
	TreeRoot = getNewRoot(TreeRoot, 1);

	// Fill out rest of tree with nodes...
	TreeRoot->left = getNewTreeNode(TreeRoot, 2);
	TreeRoot->left->left = getNewTreeNode(TreeRoot, 4);
	TreeRoot->left->right = getNewTreeNode(TreeRoot, 5);
	TreeRoot->right = getNewTreeNode(TreeRoot, 3);

	// Print out values in binary tree
	int print = TRUE; // TRUE TO PRINT, FALSE TO NOT PRINT

	printf("The tree traversed inorder: ");
	traverseTreeInOrder(TreeRoot, print);
	printf("\n\n");

	printf("The tree traversed preorder: ");
	traverseTreePreOrder(TreeRoot, print);
	printf("\n\n");

	printf("The tree traversed postorder: ");
	traverseTreePostOrder(TreeRoot, print);
	printf("\n\n");

	system("pause");
}