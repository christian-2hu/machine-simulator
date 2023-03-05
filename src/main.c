#include <stdio.h>
#include <stdlib.h>
#include "parser.c"

int main(int argc,  char *argv[]) {
    if(argc <= 1) {
        printf("Error, file not found.\n");
        exit(EXIT_FAILURE);
    }
    parser(argv[1]);
    return 0;
}
