/***************************************
Implementation of binary search tree.
***************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"


struct Node {
	TYPE val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int cnt;
};

void initBSTree(struct BSTree *tree)
{
	tree->cnt = 0;
	tree->root = 0;
}

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
	}
}

void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

struct Node *_addNode(struct Node *cur, TYPE val)
{
	struct Node *newNode;
	if(cur == 0)
	{
		newNode = malloc(sizeof(struct Node));
		assert(newNode != 0);
		newNode->val = val;
		newNode->left = newNode->right = 0;
		return newNode;
	}
	if(compare(val, cur->val) == -1)
		cur->left = _addNode(cur->left, val);
	else if(compare(val, cur->val) == 1)
		cur->right = _addNode(cur->right, val);
	return cur;
}

void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}

int containsBSTree(struct BSTree *tree, TYPE val)
{
        assert(val != 0);
	struct BSTree *tmp = newBSTree();
	assert(tmp != 0);
	
	if(compare(val, tree->root->val) == 0)
	{
	    clearBSTree(tmp);
	    deleteBSTree(tmp);
       	    return 1;
	}
	else if(compare(val, tree->root->val) == -1)
	{
	    tmp->root = tree->root->left;
	    
	}
	else if(compare(val, tree->root->val) == 1)
	{
	    tmp->root = tree->root->right;
	    
	}	
	if(tmp->root == NULL)
	{
	  clearBSTree(tmp);
	  deleteBSTree(tmp);
	  return 0;
	}

	return containsBSTree(tmp, val);
}

TYPE _leftMost(struct Node *cur)
{
	if(cur->left == NULL)
		return cur->val;
	else
		return _leftMost(cur->left);
}

struct Node *_removeLeftMost(struct Node *cur)
{
  if(cur->left == 0)
	{
	  //if(cur->right == 0)
	  //_freeBST(cur);
	  //else
	  //_removeLeftMost(cur->right);
	  return cur;
		
	}
	//else
	  //return cur = cur->left;
	
	return _removeLeftMost(cur->left);
}

struct Node *_removeNode(struct Node *cur, TYPE val)
{
        assert(cur != 0);
	assert(val != 0);
	 
	if(compare(val, cur->val) == 0)
	{
		if(cur->right == 0)
		     return cur->left;
		else
		{
			cur->val = _leftMost(cur->right);
			cur->right = _removeLeftMost(cur->right);
		}
	}
	else if(compare(val, cur->val) == -1)
		cur->left = _removeNode(cur->left, val);
	else
		cur->right = _removeNode(cur->right, val);
	
	return cur;
}

void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

