#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#define TRUE 1
#define FALSE 0

Root * getNewRoot(Root *NewRoot, int data)
{
	NewRoot = (Root*)malloc(sizeof(Root));
	NewRoot->data = data;
	NewRoot->left = NULL;
	NewRoot->right = NULL;

	return NewRoot;
}

TreeNode * getNewTreeNode(Root *Tree, int data)
{
	TreeNode * Node = (TreeNode*)malloc(sizeof(TreeNode));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

void traverseTreeInOrder(Root *Tree, int print)
{
	if (Tree == NULL)
	{
		return;
	}

	traverseTreeInOrder(Tree->left, print);
	if (print == TRUE)
	{
		printf("%d ", Tree->data);
	}
	traverseTreeInOrder(Tree->right, print);
}

void traverseTreePreOrder(Root *Tree, int print)
{
	if (Tree == NULL)
	{
		return;
	}

	if (print == TRUE)
	{
		printf("%d ", Tree->data);
	}
	traverseTreePreOrder(Tree->left, print);
	traverseTreePreOrder(Tree->right, print);
}

void traverseTreePostOrder(Root *Tree, int print)
{
	if (Tree == NULL)
	{
		return;
	}

	traverseTreePostOrder(Tree->left, print);
	traverseTreePostOrder(Tree->right, print);
	if (print == TRUE)
	{
		printf("%d ", Tree->data);
	}
}