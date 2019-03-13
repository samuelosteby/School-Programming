#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "integerarray.h"
#define TRUE 1
#define FALSE 0

Root * getNewRoot(Root *NewRoot, int data)
{
	if (isEmpty(NewRoot)) // If the root doesn't already exist...
	{
		// Allocate memory, create and return root
		NewRoot = (Root*)malloc(sizeof(Root));
		NewRoot->data = data;
		NewRoot->left = NULL;
		NewRoot->right = NULL;

		return NewRoot;
	}
	else
	{
		printf("Tree already exists!\n\n");
		return NULL;
	}
}

TreeNode * getNewTreeNode(Root *Tree, int data)
{
	// Allocate, create and return node
	TreeNode * Node = (TreeNode*)malloc(sizeof(TreeNode));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

void traverseTreeInOrder(Root *Tree)
{
	if (Tree == NULL) // Base case
	{
		return;
	}

	// Traverse and print inorder
	traverseTreeInOrder(Tree->left);
	printf("%d ", Tree->data);
	traverseTreeInOrder(Tree->right);
}

void traverseTreePreOrder(Root *Tree)
{
	if (Tree == NULL) // Base case
	{
		return;
	}

	// Traverse and print in preorder
	printf("%d ", Tree->data);
	traverseTreePreOrder(Tree->left);
	traverseTreePreOrder(Tree->right);
}

void traverseTreePostOrder(Root *Tree)
{
	if (Tree == NULL) // Base case
	{
		return;
	}

	// Traverse and print in postorder
	traverseTreePostOrder(Tree->left);
	traverseTreePostOrder(Tree->right);
	printf("%d ", Tree->data);
}

int isEmpty(Root *Tree)
{
	// Check whether the tree's root is NULL or not
	if (Tree == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

TreeNode * insert(Root *Tree, TreeNode *Node)
{
	if (isEmpty(Tree)) // If the root is empty...
	{
		Tree = Node;
		return Tree;
	}
	else
	{
		if (Tree->data >= Node->data) // If the current node is bigger than the insert node
		{
			if (Tree->left == NULL) // If there's no smaller data, put this node to the left of the current one
			{
				Tree->left = Node;
				return Node;
			}
			else // If there is smaller data... Try again with the smaller node
			{
				insert(Tree->left, Node);
				return NULL;
			}
		}
		else // If the current node is smaller than the insert node
		{
			if (Tree->right == NULL) // If there's no bigger data, put this node to the right of the current one
			{
				Tree->right = Node;
				return Node;
			}
			else // If there is bigger data... Try again with the bigger node
			{
				insert(Tree->right, Node);
				return NULL;
			}
		}
	}
}

Root * search(Root *Tree, int data)
{
	if (isEmpty(Tree)) // If the tree is empty...
	{
		return NULL;
	}
	else if (Tree->data == data) // Base case
	{
		return Tree;
	}

	if (Tree->data < data) // If the data is bigger than the current node's data, go right
	{
		return search(Tree->right, data);
	}
	else // If the data is smaller than the current node's data, go left
	{
		return search(Tree->left, data);
	}
}

TreeNode * minimum(Root *Tree)
{
	if (isEmpty(Tree))
	{
		return NULL;
	}
	else
	{
		while (Tree->left != NULL) // Keep traversing to the left until the minimum is found
		{
			Tree = Tree->left;
		}

		return Tree;
	}
}

TreeNode * maximum(Root *Tree)
{
	if (isEmpty(Tree))
	{
		return NULL;
	}
	else
	{
		while (Tree->right != NULL) // Keep traversing to the right until the maximum is found
		{
			Tree = Tree->right;
		}

		return Tree;
	}
}

TreeNode * delete(Root *Tree, TreeNode *Node)
{
	if (isEmpty(Node)) // If the node doesn't exist...
	{
		return NULL;
	}

	// Base case 
	if (isEmpty(Tree))
	{
		return Tree;
	}

	if (Node->data < Tree->data) // If the node's data is smaller than the current node's data, look left
	{
		Tree->left = delete(Tree->left, Node);
	}
	else if (Node->data > Tree->data) // If the node's data is bigger than the current node's data, look right
	{
		Tree->right = delete(Tree->right, Node);
	}
	else // If the data is the same and the right node is found...
	{
		// If the node has one or no following nodes...
		if (Tree->left == NULL)
		{
			TreeNode *temp = Tree->right;
			free(Tree);
			return temp;
		}
		else if (Tree->right == NULL)
		{
			TreeNode *temp = Tree->left;
			free(Tree);
			return temp;
		}

		// If the node has two following nodes, find inorder successor
		TreeNode* temp = minimum(Tree->right);

		// Copy inorder successor
		Tree->data = temp->data;

		// Delete inorder successor 
		Tree->right = delete(Tree->right, temp);
	}
	return Tree;
}

TreeNode * predecessor(Root *Tree, TreeNode *Node)
{

	if (Tree == NULL) // If the binary tree is empty...
	{
		return NULL;
	}

	if (Node == NULL) // If the node to be used doesn't exist...
	{
		return NULL;
	}

	if (search(Tree, Node->data) != NULL) // If the node's data exists in the tree...
	{
		Node = search(Tree, Node->data); // Ensure that the node being used is in the same tree as the node
	}
	else // If the node doesn't exist in the tree...
	{
		int i = 1;
		if (Node->data < maximum(Tree)->data) // If the node's data is less than the maximum data of the tree...
		{
			for (i = 1; i + Node->data <= maximum(Tree)->data; i++) // Find the nearest successor and use it
			{
				if (search(Tree, Node->data + i) != NULL)
				{
					Node = search(Tree, Node->data + i);
					break;
				}
			}
		}
		else // If the node's data is the maximum of the tree or higher...
		{
			for (i = 1; Node->data - i >= minimum(Tree)->data; i++) // Find the nearest predecessor and return it
			{
				if (search(Tree, Node->data - i) != NULL)
				{
					Node = search(Tree, Node->data - i);
					return Node;
				}
			}
		}
	}

	if (Node->left != NULL) // If the subtree to the left isn't NULL, the predecessor is the maximum data in the left subtree
	{
		return maximum(Node->left);
	}
	else // If the subtree to the left is NULL, start from the root, travel down tree. Right if bigger, left if smaller than root's data
	{
		TreeNode *predecessor = NULL; // Placeholder for predecessor

		while (Tree != NULL)
		{
			if (Node->data > Tree->data) // Go right and put placeholder as the current node
			{
				predecessor = Tree;
				Tree = Tree->right;
			}
			else if (Node->data < Tree->data) // Go left instead
			{
				Tree = Tree->left;
			}
			else // Return the predecessor
			{
				return predecessor;
			}
		}

		return predecessor;
	}
}

TreeNode * successor(Root *Tree, TreeNode *Node)
{
	if (Tree == NULL) // If the binary tree is empty...
	{
		return NULL;
	}

	if (Node == NULL) // If the node to be used doesn't exist...
	{
		return NULL;
	}

	if (search(Tree, Node->data) != NULL) // If the node's data exists in the tree...
	{
		Node = search(Tree, Node->data); // Ensure that the node being used is in the same tree as the node
	}
	else // If the node doesn't exist in the tree...
	{
		int i = 1;
		if (Node->data < maximum(Tree)->data) // If the node's data is less than the maximum data of the tree...
		{
			for (i = 1; i + Node->data <= maximum(Tree)->data; i++) // Find the nearest successor and return it
			{
				if (search(Tree, Node->data + i) != NULL)
				{
					Node = search(Tree, Node->data + i);
					return Node;
				}
			}
		}
		else // If the node's data is the maximum of the tree or higher...
		{
			for (i = 1; Node->data - i >= minimum(Tree)->data; i++) // Find the nearest successor and return it
			{
				if (search(Tree, Node->data - i) != NULL)
				{
					Node = search(Tree, Node->data - i);
					return Node;
				}
			}
		}
	}
	
	if (Node->right != NULL) // If the subtree to the right isn't NULL, the successor is the minimum data in the right subtree
	{
		return minimum(Node->right);
	}
	else // If the subtree to the right is NULL, start from the root, travel down tree. Right if bigger, left if smaller than root's data
	{
		TreeNode *successor = NULL; // Placeholder for successor

		while (Tree != NULL)
		{
			if (Node->data < Tree->data) // Go left and put the placeholder as the current node
			{
				successor = Tree;
				Tree = Tree->left;
			}
			else if (Node->data > Tree->data) // Go right instead
			{
				Tree = Tree->right;
			}
			else // Return the successor
			{
				return successor;
			}
		}

		return successor;
	}
}

int depth(Root *Tree)
{
	if (isEmpty(Tree)) // If the tree is empty...
	{
		return 0;
	}
	else
	{
		// Calculate the depths of the left subtree and the right subtree
		int leftdepth = depth(Tree->left);
		int rightdepth = depth(Tree->right);

		// Return the depth of the deepest subtree
		if (leftdepth > rightdepth)
		{
			return leftdepth + 1;
		}
		else
		{
			return rightdepth + 1;
		}
	}
}

int size(Root *Tree)
{
	if (isEmpty(Tree)) // If the tree is empty...
	{
		return 0;
	}
	else
	{
		return(size(Tree->left) + 1 + size(Tree->right)); // Teturn the total amount of nodes in the tree
	}
}

void freeTree(Root *Tree)
{
	if (isEmpty(Tree) == FALSE) // Base case
	{
		// Free binary tree through postorder traversal
		freeTree(Tree->right);
		freeTree(Tree->left);
		free(Tree);
	}
}