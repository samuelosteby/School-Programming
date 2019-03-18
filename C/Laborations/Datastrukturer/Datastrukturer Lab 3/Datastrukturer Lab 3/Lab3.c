#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "integerarray.h"
#define TRUE 1
#define FALSE 0

// Made by: Samuel Östeby

int main()
{
	// Lab 3
	// Exercise 1
	printf("Exercise 1:\n");

	// Create binary tree root...
	Root * TreeRoot = NULL;
	// Fill out rest of tree with nodes...
	TreeNode * Node1 = NULL;
	TreeNode * Node2 = NULL;
	TreeNode * Node3 = NULL;
	TreeNode * Node4 = NULL;
	TreeNode * Node5 = NULL;

	// Test if tree is empty
	printf("Testing if the binary tree is empty...\n");
	if (isEmpty(TreeRoot))
	{
		printf("Tree is empty!\n\n");
	}

	// Create root and nodes
	printf("Creating tree...\n\n");

	TreeRoot = getNewRoot(TreeRoot, 10);
	Node1 = getNewTreeNode(Node1, 8);
	Node2 = getNewTreeNode(Node2, 6);
	Node3 = getNewTreeNode(Node3, 9);
	Node4 = getNewTreeNode(Node4, 20);
	Node5 = getNewTreeNode(Node5, 15);
	print(Node1);

	search(Node1, 1);
	printf("%d", search(Node1, 1));
	
	// Insert nodes into root / Tree
	insert(TreeRoot, Node1);
	insert(TreeRoot, Node2);
	insert(TreeRoot, Node3);
	insert(TreeRoot, Node4);
	insert(TreeRoot, Node5);

	// Print out values in binary tree inorder
	printf("The tree traversed inorder / sorted order: ");
	traverseTreeInOrder(TreeRoot);
	printf("\n\n");

	// Find the smallest data in tree
	printf("The smallest data in the tree is: %d\n", minimum(TreeRoot)->data);
	// Find the biggest data in tree
	printf("The biggest data in the tree is: %d\n\n", maximum(TreeRoot)->data);

	// !!Delete comment marks below to delete node from tree!!
	//delete(TreeRoot, search(TreeRoot, 20));
	//printf("The tree after deletion: ");
	//traverseTreeInOrder(TreeRoot);
	//printf("\n\n");

	// Find successor to node with data 15
	if (successor(TreeRoot, search(TreeRoot, 15)) != NULL)
	{
		printf("The successor to node with data 15 is: %d\n", successor(TreeRoot, search(TreeRoot, 15))->data);
	}
	else
	{
		printf("There is no successor to node with data 15\n");
	}

	// Find predecessor to node with data 15
	if (predecessor(TreeRoot, search(TreeRoot, 15)) != NULL)
	{
		printf("The predecessor to node with data 15 is: %d\n\n", predecessor(TreeRoot, search(TreeRoot, 15))->data);
	}
	else
	{
		printf("There is no predecessor to node with data 15\n\n");
	}

	// Calculate depth of tree
	printf("The depth of the tree is: %d\n", depth(TreeRoot));
	// Calculate size of tree
	printf("The size of the tree is: %d\n\n\n", size(TreeRoot));

	printf("Exercise 2:\n");

	//Create and populate two new binary trees based on lists from lab 1
	Root * Lab1Tree1_1 = NULL;
	TreeNode * Lab1Node1_1 = NULL;
	TreeNode * Lab1Node1_2 = NULL;
	TreeNode * Lab1Node1_3 = NULL;
	TreeNode * Lab1Node1_4 = NULL;
	TreeNode * Lab1Node1_5 = NULL;


	Lab1Tree1_1 = getNewRoot(Lab1Tree1_1, 3);
	Lab1Node1_1 = getNewTreeNode(Lab1Node1_1, 1);
	Lab1Node1_2 = getNewTreeNode(Lab1Node1_2, 5);
	Lab1Node1_3 = getNewTreeNode(Lab1Node1_3, 10);
	Lab1Node1_4 = getNewTreeNode(Lab1Node1_4, 8);
	Lab1Node1_5 = getNewTreeNode(Lab1Node1_5, 7);

	Root * Lab1Tree2_1 = NULL;
	TreeNode * Lab1Node2_1 = NULL;
	TreeNode * Lab1Node2_2 = NULL;
	TreeNode * Lab1Node2_3 = NULL;
	TreeNode * Lab1Node2_4 = NULL;
	TreeNode * Lab1Node2_5 = NULL;

	Lab1Tree2_1 = getNewRoot(Lab1Tree2_1, 5);
	Lab1Node2_1 = getNewTreeNode(Lab1Node2_1, 2);
	Lab1Node2_2 = getNewTreeNode(Lab1Node2_2, 9);
	Lab1Node2_3 = getNewTreeNode(Lab1Node2_3, 6);
	Lab1Node2_4 = getNewTreeNode(Lab1Node2_4, 1);
	Lab1Node2_5 = getNewTreeNode(Lab1Node2_5, 2);

	insert(Lab1Tree1_1, Lab1Node1_1);
	insert(Lab1Tree1_1, Lab1Node1_2);
	insert(Lab1Tree1_1, Lab1Node1_3);
	insert(Lab1Tree1_1, Lab1Node1_4);
	insert(Lab1Tree1_1, Lab1Node1_5);

	insert(Lab1Tree2_1, Lab1Node2_1);
	insert(Lab1Tree2_1, Lab1Node2_2);
	insert(Lab1Tree2_1, Lab1Node2_3);
	insert(Lab1Tree2_1, Lab1Node2_4);
	insert(Lab1Tree2_1, Lab1Node2_5);

	// Traverse the trees in order and print their nodes' data out
	printf("Lab1 Tree 1 traversed inorder / sorted order: ");
	traverseTreeInOrder(Lab1Tree1_1);
	printf("\n\n");

	printf("Lab1 Tree 2 traversed inorder / sorted order: ");
	traverseTreeInOrder(Lab1Tree2_1);
	printf("\n\n");

	if (isEmpty(Lab1Tree1_1) == FALSE)
	{
		// Find the smallest data in tree
		printf("The minimum in Lab1 Tree 1 is: %d\n", minimum(Lab1Tree1_1)->data);
		// Find the biggest data in tree
		printf("The maximum in Lab1 Tree 1 is: %d\n\n", maximum(Lab1Tree1_1)->data);
	}

	if (isEmpty(Lab1Tree2_1) == FALSE)
	{
		// Find the smallest data in tree
		printf("The minimum in Lab1 Tree 2 is: %d\n", minimum(Lab1Tree2_1)->data);
		// Find the biggest data in tree
		printf("The maximum in Lab1 Tree 2 is: %d\n\n", maximum(Lab1Tree2_1)->data);
	}

	// Successor to node with data 5 in Lab1 Tree 1
	if (successor(Lab1Tree1_1, search(Lab1Tree1_1, 5)) != NULL)
	{
		printf("The successor to node with data 5 in Lab1 Tree 1 is: %d\n", successor(Lab1Tree1_1, search(Lab1Tree1_1, 5))->data);
	}
	else
	{
		printf("There is no successor to node with data 5 in Lab1 Tree 1\n");
	}

	// Predecessor to node with data 5 in Lab1 Tree 1
	if (predecessor(Lab1Tree1_1, search(Lab1Tree1_1, 5)) != NULL)
	{
		printf("The predecessor to node with data 5 in Lab1 Tree 1 is: %d\n\n", predecessor(Lab1Tree1_1, search(Lab1Tree1_1, 5))->data);
	}
	else
	{
		printf("There is no predecessor to node with data 5 in Lab1 Tree 1\n\n");
	}

	// Successor to node with data 9 in Lab1 Tree 2
	if (successor(Lab1Tree2_1, search(Lab1Tree2_1, 9)) != NULL)
	{
		printf("The successor to node with data 9 in Lab1 Tree 2 is: %d\n", successor(Lab1Tree2_1, search(Lab1Tree2_1, 9))->data);
	}
	else
	{
		printf("There is no successor to node with data 9 in Lab1 Tree 2\n");
	}

	// Predecessor to node with data 9 in Lab1 Tree 2
	if (predecessor(Lab1Tree2_1, search(Lab1Tree2_1, 9)) != NULL)
	{
		printf("The predecessor to node with data 9 in Lab1 Tree 2 is: %d\n\n", predecessor(Lab1Tree2_1, search(Lab1Tree2_1, 9))->data);
	}
	else
	{
		printf("There is no predecessor to node with data 9 in Lab1 Tree 1\n\n");
	}

	// Predecessor to maximum of Lab1 Tree 1 in Lab1 Tree 2
	if (predecessor(Lab1Tree2_1, maximum(Lab1Tree1_1)) != NULL)
	{
		printf("The predecessor to maximum of Lab1 Tree 1 in Lab1 Tree 2 is: %d\n", predecessor(Lab1Tree2_1, maximum(Lab1Tree1_1))->data);
	}
	else
	{
		printf("There is no predecessor to maximum of Lab1 Tree 1 in Lab1 Tree 2\n");
	}

	// Predecessor to maximum of Lab1 Tree 2 in Lab1 Tree 1
	if (predecessor(Lab1Tree1_1, maximum(Lab1Tree2_1)) != NULL)
	{
		printf("The predecessor to maximum of Lab1 Tree 2 in Lab1 Tree 1 is: %d\n\n\n", predecessor(Lab1Tree1_1, maximum(Lab1Tree2_1))->data);
	}
	else
	{
		printf("There is no predecessor to maximum of Lab1 Tree 2 in Lab1 Tree 1\n\n\n");
	}

	printf("Exercise 3:\n");
	// Create array and add data
	printf("Creating array...\n\n");

	Intarray * Iarray = NULL;
	Iarray = getNewIntarray(Iarray, 10);
	Iarray->data[0] = 9;
	Iarray->data[1] = 6;
	Iarray->data[2] = 0;
	Iarray->data[3] = 7;
	Iarray->data[4] = 10;
	Iarray->data[5] = 0;
	Iarray->data[6] = 0;
	Iarray->data[7] = 1;
	Iarray->data[8] = 3;
	Iarray->data[9] = 9;

	// Print the array in it's regular form
	printArray(Iarray);

	// Print the sorted array
	sortArray(Iarray);

	system("pause");
}