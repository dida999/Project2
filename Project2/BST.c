#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "TreePrintLibrary (1).h"
#define check(node)\
if(node == NULL){\
printf("allocation failed");\
exit(1);\
 }
#define sum(root){\
int sum=countElements(root);\
return sum;}

void main()
{
	BST bst;
	initBST(&bst);
	insertBST(&bst, 5);
	insertBST(&bst,3);
	insertBST(&bst, 1);
	insertBST(&bst, 7);
	insertBST(&bst, 8);
	insertBST(&bst, 4);
	insertBST(&bst, 6);
	printTreeInorder(&bst);
	printf("\nthe amount of elements are %d", countElements(bst.root));
	printf("\nthe index from last is %d ", findIndexNFromLast(&bst,5));
	printf("\n the sub trees are the same height: %d ", sameHeightLeaves(&bst));
	/*destroyBST(&bst);*/
}

void initBST(BST* bst)
{
	bst->root = NULL;
}

TreeNode* createNode(int value) //creating new tree node
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
	check(node);
	node->left = NULL;
	node->right = NULL;
	node->element = value;
	return node;
}

void insertBST(BST* bst, int value)
{
	if ((bst->root) == NULL) { //puting value in root if tree is empty
		bst->root = createNode(value);
		return;
	}
	else
	if (bst->root->element >= value)
		if (bst->root->left == NULL)//left
		{
			bst->root->left = createNode(value);
			return;
		}
		else
			insertBST(bst->root->left, value);
	if (bst->root->element <= value)
		if (bst->root->right == NULL)//right
		{
			bst->root->right = createNode(value);
			return;
		}
		else
			insertBST(bst->root->right, value);
}

void printSubTreeInOrder(TreeNode* root)
{
	//first the sub left tree
	//then the root 
	// then the sub right tree
	if (root != NULL)
	{
		printSubTreeInOrder(root->left);
		printf("%d  ", root->element);
		printSubTreeInOrder(root->right);
	}
}

void printTreeInorder(BST* bst)
{
	if (bst->root == NULL)// if there are no elements
	{
		printf("the tree is empty");
	}
	else
	{
		printSubTreeInOrder(bst->root);// call the recursive function and print by order
	}
}

void destroysubBST(TreeNode* root)
{
	//first the sub left tree
		// then the sub right tree
		//then the root
		if (root != NULL)
		{
			destroysubBST(root->left);
			destroysubBST(root->right);
			free(root);
		}

}

void destroyBST(BST* bst)
{
	if (bst->root == NULL)// if there are no elements
	{
		return;
	}
	else
	{
		destroysubBST(bst->root);// call the recursive function that will free the elements by order
	}
}

int findMaxValueInSubTree(TreeNode* root)
{
	int left, right, max;
	if (root == NULL) return -1; //tree is empty
	left = findMaxValueInSubTree(root->left); //searching in left side
	right = findMaxValueInSubTree(root->right); //searching in right side
	max = left > right ? left : right; //comparing right max and left max
	max = max > root->element ? max : root->element; //comparing max to root
	return max;
}

int countElements(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
		return 1 + countElements(root->left) + countElements(root->right);
}

int findIndexNFromLast(BST* bst, int N)
{
	int amountOfElements = 0;
	//we will first check that our tree has at least n elements and is not equal to null
	amountOfElements = countElements(bst->root);
	if (amountOfElements < N)
	{
		return -1;
	}
	return findSubIndexNFromLast(bst->root, N);
}

int findSubIndexNFromLast(TreeNode* root, int N)
{
	int amountRight = countElements(root->right);
	if (amountRight == N - 1)//if N-1 is the amount on right the index is root
	{
		return root->element;
	}
	if (amountRight > N - 1) //recursive call searching in right
	{
		return findSubIndexNFromLast(root->right, N);
	}
	else//recursive call searching in left
	{
		return findSubIndexNFromLast(root->left, N - amountRight - 1);
	}
}

int sameSubHeightLeaves(TreeNode* root)
{
	if (root == NULL)
	{
		return INT_MIN;
	}
	// now we will count what is the height of the roots left son and right son
	int leftHeight = sameSubHeightLeaves(root->left);
	int rightHeight = sameSubHeightLeaves(root->right);
	//if they are equal return 1 if they aren't equal return 0  
	return (rightHeight = leftHeight) ? 1 : 0;
}

int sameHeightLeaves(BST* bst)
{
	return sameSubHeightLeaves(bst->root);
}




