#include "hbt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void evaluateTree(char * filename){
    FILE * fp;
    fp = fopen(filename, "rb");
    int openFile = 0;
    int BST = 0;
    int balanced = 0;

    if(!fp){
        openFile = -1; 

    }
    else{
    Tnode * root = BuildTree(fp);
    BST = isBST(root);
    balanced = isBalanced(root);
    }

    printf("%d, %d, %d", openFile, BST, balanced);
    fclose(fp);

}

// build tree RECURSIVE
Tnode * BuildTree(FILE * fp){
    int key;
    fread(&key, sizeof(int), 1, fp);
    char children;
    fread(&children, sizeof(char), 1, fp);

    Tnode * newNode = createNode(key);

    if(children == 0){
        newNode -> height = 1;
        return newNode;
    }
    else if(children == 1){
        newNode->right = BuildTree(fp);
        newNode->height = calcHeight(newNode);
    }
    else if(children == 2){
        newNode -> left = BuildTree(fp);
        newNode->height = calcHeight(newNode);
    }
    else if(children == 3){
        newNode -> left = BuildTree(fp);
        newNode -> right = BuildTree(fp);
        newNode -> height = calcHeight(newNode);
    }
    else{
        printf("the number of children was not 0/1/2/3");
    }
    return newNode;


}

void DeleteTree(Tnode * node){
    if (node == NULL){
        return; // if the node is null or at the end, do nothing
    }

    DeleteTree(node->left);
    DeleteTree(node->right);

    free(node);
}

// is whole tree BST
int isBST(Tnode * root){
    if (root == NULL){
        return 1;
    }

    if (root->left != NULL && root->key < root->left->key){ // can it be equal to? no
        // left cannot be greater
        return 0;
    }

    if (root -> right != NULL && root->key > root->right->key)
    {
        return 0;
    }

    return(isBST(root->left) & isBST(root->right));
}

// tell if ONE node is balanced
int isBalanced(Tnode * root){
    if (root == NULL){
        return 1;
    }

    int leftHeight = root->left->height;
    int rightHeight = root->right->height;

    if(leftHeight-rightHeight < -1 || leftHeight-rightHeight > 1){
        return 0;
    }
    else 
        return 1;
}
