#include "hbt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Tnode * createNode(int val){
    Tnode * newNode = NULL;
    newNode = malloc(sizeof(Tnode));
    newNode -> key = val;
    newNode -> height = 0;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Tnode * InsertVal(Tnode * root, int insert){

    // first root
    if (root == NULL)
        return(createNode(insert));
    
    if (insert <= root->key){
        root->left = InsertVal(root->left, insert);
    }
    else{
        root->right = InsertVal(root->right, insert);
    }

    root->height = calcHeight(root);

    // check balance

    int balance;
    balance = calcBalance(root);

    if(balance > 1){
        if(insert <= root->left->key)
            return cwRotation(root);
        else if (insert > root->left->key){
            root->left = cntcwRotation(root->left);
            return cwRotation(root);
        }
    }
    else if(balance < -1){
        if( insert <= root->right->key){
            root->right = cwRotation(root->right);
            return(cntcwRotation(root));
        }
        else if(insert > root->right->key){
            return(cntcwRotation(root));
        }

    }
    return root;
    
}

Tnode * DeleteNode(Tnode * root, int val){
    if(root == NULL){
        return root;
    }

    // navigate tree
    if(val < root->key){
        root->left = DeleteNode(root->left, val);
    }
    else if( val > root->key){
        root->right = DeleteNode(root->right, val);
    }
    else{
        // if this value is found
        // check for children
        Tnode * temp = NULL;
        // no children or 1 child
        if(root->left == NULL || root->right == NULL){
            if(root->left){
                temp = root->left;
            }
            else{
                temp = root->right;
            }
        
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }

            free(temp);
        }
        else{
            temp = ImmPred(root);
            root->key = temp->key;
            root->right = DeleteNode(root->left, temp->key); // assign to root->right
        }
    }

    if(root == NULL)
        return root;

    root->height = calcHeight(root);
    int balance = calcBalance(root);

    if(balance > 1){
        if(calcBalance(root->left) >= 0){
            return(cwRotation(root));
        }
        else{
            root->left = cntcwRotation(root->left);
            return cwRotation(root);
        }
    }
    else if(balance < -1){
        if(calcBalance(root->right) <= 0){
            return cntcwRotation(root);
        }
        else{
            root->right = cwRotation(root->right);
            return cntcwRotation(root);
        }
    }

    return root;
}


Tnode * ImmPred(Tnode * curr){
    Tnode * immPred = curr -> left;
    while (immPred -> right != NULL){
        immPred = immPred -> right;}
    
    return immPred;
}
