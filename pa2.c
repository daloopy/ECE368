#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hbt.h"

int main(int argc, char *argv[]){
    if (argc != 4) // incorrect num of arguments ;      is this 4?**********
    {
        return EXIT_FAILURE;
    }
    else if (strcmp(argv[1], "-b") == 0) // building 
    {
        int output; // exit success or failure
        output = buildTree(argv[2]);
        return output;
    }
    else if(strcmp(argv[1], "-e") == 0) // evaluating 
    {


        return EXIT_SUCCESS;
    }


    return EXIT_FAILURE;;
}
