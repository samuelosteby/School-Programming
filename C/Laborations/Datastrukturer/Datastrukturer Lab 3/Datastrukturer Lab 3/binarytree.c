#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#define TRUE 1
#define FALSE 0

Root * getNewRoot(Root *NewRoot, int data)
{
	if (isEmpty(NewRoot))
	{
		NewRoot = (Root*)malloc(sizeof(Root));
		NewRoot->data = data;
		NewRoot->left = NULL;
		NewRoot->right = NULL;

		return NewRoot;
	}
	else
	{
		printf("Root already exists!\n\n");
		return NULL;
	}
}

TreeNode * getNewTreeNode(Root *Tree, int data)
{
	TreeNode * Node = (TreeNode*)malloc(sizeof(TreeNode));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

void traverseTreeInOrder(Root *Tree)
{
	if (Tree == NULL)
	{
		return;
	}

	traverseTreeInOrder(Tree->left);
	printf("%d ", Tree->data);
	traverseTreeInOrder(Tree->right);
}

void traverseTreePreOrder(Root *Tree)
{
	if (Tree == NULL)
	{
		return;
	}

	printf("%d ", Tree->data);
	traverseTreePreOrder(Tree->left);
	traverseTreePreOrder(Tree->right);
}

void traverseTreePostOrder(Root *Tree)
{
	if (Tree == NULL)
	{
		return;
	}

	traverseTreePostOrder(Tree->left);
	traverseTreePostOrder(Tree->right);
	printf("%d ", Tree->data);
}

int isEmpty(Root *Tree)
{
	if (Tree == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

TreeNode * insert(Root *Tree, TreeNode *TreeNode)
{
	if (isEmpty(Tree))
	{
		Tree = TreeNode;
		return Tree;
	}
	else
	{
		if (Tree->data >= TreeNode->data)
		{
			if (Tree->left == NULL)
			{
				Tree->left = TreeNode;
				return TreeNode;
			}
			else
			{
				insert(Tree->left, TreeNode);
				return NULL;
			}
		}
		else
		{
			if (Tree->right == NULL)
			{
				Tree->right = TreeNode;
				return TreeNode;
			}
			else
			{
				insert(Tree->right, TreeNode);
				return NULL;
			}
		}
	}
}

Root * search(Root *Tree, int data)
{
	if (isEmpty(Tree))
	{
		return NULL;
	}
	else if (Tree->data == data)
	{
		return Tree;
	}

	if (Tree->data < data)
	{
		return search(Tree->right, data);
	}

	return search(Tree->left, data);
}

TreeNode * delete(Root *Tree, TreeNode *TreeNode)
{
	printf("Ayy lmao\n\n");
}