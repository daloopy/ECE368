#ifndef __HBT_TREE__
#define __HBT_TREE__
#include <stdio.h>

typedef struct _Tnode {
   int key;
   int height;
   struct _Tnode *left;
   struct _Tnode *right;
} Tnode;

Tnode * createNode(int val);
Tnode * InsertVal(Tnode * root, int insert);
Tnode * DeleteNode(Tnode * root, int val);
Tnode * ImmPred(Tnode * curr);

Tnode * cwRotation(Tnode * old_root);
Tnode * cntcwRotation(Tnode * old_root);
int calcTreeHeight(Tnode * node);
int calcHeight(Tnode * node);
int calcBalance(Tnode * node);

int buildTree(char * filename);

int main(int argc, char *argv[]);

Tnode * BuildTree(FILE * fp);
void evaluateTree(char * filename);
void DeleteTree(Tnode * node);
int isBST(Tnode * root);
int isBalanced(Tnode * root);

#endif
