#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"

void parse(FILE *file) {
    char ch;
    char buffer[256];

    while(fgets(buffer, 256, file) != NULL) {
        printf("%s", buffer);
    }
}

void parser(char *filename) {
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE);
    }

    parse(file);
    fclose(file);
}
