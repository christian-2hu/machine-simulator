#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *new_node() {
    Node *head = NULL;
    return head;
}

void stack_push(Node **stack, int data) {
    if(*stack == NULL) {
        *stack = malloc(sizeof(Node));
        (*stack)->data = data;
        (*stack)->next = NULL;
        return;
    }
    Node *newNode = new_node();
    newNode = malloc(sizeof(Node));
    newNode->next = *stack;
    newNode->data = data;
    *stack = newNode;
}

int stack_pop(Node **stack) {
    if(stack == NULL) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    int popped = (*stack)->data;
    *stack = (*stack)->next;
    return popped;
}

int stack_get_size(Node *stack) {
    Node *ptr = stack;
    int size = 0;
    if(stack != NULL) {
        while(ptr != NULL) {
            size++;
            ptr = ptr->next;
        }
    }
    return size;
}

int stack_peek(Node *stack) {
    if(stack == NULL) {
        return 0;
    }
    return stack->data;
}