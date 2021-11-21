#include "hbt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buildTree(char * filename){
    FILE * fp;
    fp = fopen(filename, "rb");
    int openFile = 0;
    int FormatError = 0;
    int key;
    char op;
    int i = 0x69;
    int d = 0x64;
    int condition = 0;


    if(!fp){
        openFile = -1; 
        printf("%d\n", openFile);
        return EXIT_FAILURE;
    }
    Tnode * newNode = NULL;
    Tnode * root = NULL;

    fread(&key, sizeof(int), 1, fp);
    fread(&op, sizeof(char), 1, fp);

    while(fp){ // while fp not null
        if(condition) // encounter error with mem allocation or format read; place somewhere else?
        {
            FormatError = 1;
            printf("%d\n", openFile);
            return EXIT_FAILURE;
        }
    


    if(op == d){
        newNode = DeleteNode(root, key);
    }
    else if(op == i){
        if(root == NULL){
            root = InsertVal(root, key);
        }
        else{
            newNode = InsertVal(root, key);
        }

    }


    }

    openFile = 1; 
    printf("%d\n", openFile);
    fclose(fp);
    return EXIT_SUCCESS;
}    
