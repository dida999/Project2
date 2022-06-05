#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;
void initBST(BST* bst);
void insertBST(BST* bst, int value);
void printSubTreeInOrder(TreeNode* root);
TreeNode* createNode(int value);
void printTreeInorder(BST* bst);
void destroysubBST(BST* bst);
void destroyBST(BST* bst);
int findMaxValueInSubTree(TreeNode* root);
int findIndexNFromLast(BST* bst, int N);
int countElements(BST* bst);
int findSubIndexNFromLast(TreeNode* root, int N);
int sameHeightLeaves(BST* bst);
int sameSubHeightLeaves(TreeNode* root);
#endif // !_BST_ADT_H