#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include <ctype.h>

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

void parse(FILE *file) {
    char ch;
    char buffer[256];
    Node *stack = new_node();

    while(fgets(buffer, 256, file) != NULL) {
        if(strncmp("push", buffer, 4) == 0) {
            int pushed_value = 0;
            for(int i = 0; i < (int)strlen(buffer)+1; i++) {
                if(isdigit(buffer[i])) {
                    printf("%c\n", buffer[i]);
                    int casted_char = buffer[i] - '0';
                    pushed_value = concatenate(pushed_value, casted_char);
                }
                if(buffer[i] == '#') {
                    break;
                }
            }
            printf("Pushed value is %d\n", pushed_value);
            stack_push(&stack, pushed_value);
        }
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
