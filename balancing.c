#include "hbt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Tnode * cwRotation(Tnode * old_root){
    Tnode * new_root = NULL;
    new_root = old_root -> left;
    old_root -> left = new_root -> right;
    new_root -> right = old_root;

    new_root -> height = calcHeight(new_root);
    old_root -> height = calcHeight(old_root); 

    return new_root;
}

Tnode * cntcwRotation(Tnode * old_root){
    Tnode * new_root = NULL;
    new_root = old_root -> right;
    old_root -> right = new_root -> left;
    new_root -> left = old_root;

    new_root -> height = calcHeight(new_root);
    old_root -> height = calcHeight(old_root); 

    return new_root;
}

int calcTreeHeight(Tnode * node){
    int height = 0;
    if(node -> left -> height > node -> right -> height){
        height = node -> left -> height + 1;
    }
    else{
        height = node -> right -> height + 1;
    }
    return height;
}

int calcHeight(Tnode * node){
    int height = 0;
    if(node -> left -> height > node -> right -> height){
        height = node -> left -> height + 1;
    }
    else{
        height = node -> right -> height + 1;
    }
    return height;
}

int calcBalance(Tnode * node){
    int balance = 0;
    balance = (node -> left -> height) - (node -> right -> height);
    return balance;
}
