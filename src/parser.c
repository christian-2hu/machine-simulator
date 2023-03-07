#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "array.c"
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
    Array byte_line = new_array(4);
    while(fgets(buffer, 256, file) != NULL) {
        array_add(&byte_line, ftell(file));        
        if(strncmp("push", buffer, 4) == 0) {
            int pushed_value = 0;
            for(int i = 0; i < (int)strlen(buffer)+1; i++) {
                if(isdigit(buffer[i])) {
                    int casted_char = buffer[i] - '0';
                    pushed_value = concatenate(pushed_value, casted_char);
                }
                if(buffer[i] == '#') {
                    break;
                }
            }
            stack_push(&stack, pushed_value);
        }
        if(strncmp("add", buffer, 3) == 0) {
            if(stack_get_size(stack) <= 1) {
                printf("Error, you cannot add when the stack is empty or the size is less than one.\n");
                exit(EXIT_FAILURE);
            }
            int first_top = stack_pop(&stack);
            int second_top = stack_pop(&stack);
            stack_push(&stack, first_top + second_top);
        }
        if(strncmp("print", buffer, 5) == 0) {
            if(stack_get_size(stack) == 0) {
                printf("Error, the stack is empty.\n");
                exit(EXIT_FAILURE);
            }
            printf("%d\n", stack_peek(stack));
        }
        if(strncmp("pop", buffer, 3) == 0) {
            if(stack_get_size(stack) == 0 ) {
                printf("Error, cannot pop. Stack is empty!\n");
                exit(EXIT_FAILURE);
            }            
                stack_pop(&stack);
        }
        if(strncmp("dup", buffer, 3) == 0) {
            if(stack_get_size(stack) == 0) {
                printf("Error, cannot dub. Stack is empty!\n");
                exit(EXIT_FAILURE);
            }
            int temp = stack_peek(stack);
            stack_push(&stack, temp);
        }
        if(strncmp("jump", buffer, 4) == 0) {
            int address = 0;
            for(int i = 0; i < (int)strlen(buffer)+1; i++) {
                if(isdigit(buffer[i])) {
                    int casted_char = buffer[i] - '0';
                    address = concatenate(address, casted_char);
                }
                if(buffer[i] == '#') {
                    break;
                }
            }
            address--;
            if(address < 0) {
                printf("Error, can't jump to a negative line.\n");
                exit(EXIT_FAILURE);
            }
            if(address >= array_size(&byte_line)) {
                printf("Error, can't jump to a inexistent line.\n");
                exit(EXIT_FAILURE);
            }
            fseek(file, array_get(&byte_line, address), SEEK_SET);
        }
        if(strncmp("ifeq", buffer, 4) == 0) {
            int address = 0;
            for(int i = 0; i < (int)strlen(buffer)+1; i++) {
                if(isdigit(buffer[i])) {
                    int casted_char = buffer[i] - '0';
                    address = concatenate(address, casted_char);
                }
                if(buffer[i] == '#') {
                    break;
                }
            }
            if(stack_peek(stack) != 0) {
                fseek(file, array_get(&byte_line, address), SEEK_SET);
            }
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
