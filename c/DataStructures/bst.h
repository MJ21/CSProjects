/************************************************************
Binary search tree header file.
************************************************************/

#ifndef __BST_H
#define __BST_H


# ifndef TYPE
# define TYPE void*
# endif

int compare(TYPE left, TYPE right);

void print_type(TYPE curval);

struct BSTree;

/* Initialize binary search tree structure. */
void initBSTree(struct BSTree *tree);

/* Alocate and initialize search tree structure. */
struct BSTree *newBSTree();

/* Deallocate nodes in BST. */
void clearBSTree(struct BSTree *tree);

/* Deallocate nodes in BST and deallocate the BST structure. */
void deleteBSTree(struct BSTree *tree);

/*-- BST Bag interface --*/
int isEmptyBSTree(struct BSTree *tree);
int sizeBSTree(struct BSTree *tree);

void addBSTree(struct BSTree *tree, TYPE val);
int containsBSTree(struct BSTree *tree, TYPE val);
void removeBSTree(struct BSTree *tree, TYPE val);
void printTree(struct BSTree *tree);
# endif
