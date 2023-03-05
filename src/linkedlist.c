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

void list_push(Node **list, int data) {
    if(*list == NULL) {
        *list = malloc(sizeof(Node));
        (*list)->data = data;
        (*list)->next = NULL;
        return;
    }
    Node *newNode = new_node();
    newNode = malloc(sizeof(Node));
    newNode->next = *list;
    newNode->data = data;
    *list = newNode;
}

void list_add(Node **list, int data) {
    if(*list == NULL) {
        list_push(list, data);
        return;
    }
    Node *newNode = new_node();
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node *ptr = *list;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int list_pop(Node **list) {
    if(list == NULL) {
        printf("list is empty!\n");
        exit(EXIT_FAILURE);
    }
    int popped = (*list)->data;
    *list = (*list)->next;
    return popped;
}

int list_size(Node *list) {
    Node *ptr = list;
    int size = 0;
    if(list != NULL) {
        while(ptr != NULL) {
            size++;
            ptr = ptr->next;
        }
    }
    return size;
}

int list_get(Node *list, int index) {
    if(list == NULL) {
        return -1;
    }
    for(int i = 1; i < list_size(list); i++) {
        if(index == i) {
            return list->data;
        }
        list = list->next;
    }
    return list->data;
}

// Return the index where the value is at, otherwise returns -1
int list_find(Node *list, int data) {
    Node *ptr = list;
    if(list != NULL) {
        while((ptr != NULL)) {
            if(ptr->data == data) {
                return data;
            }
            ptr = ptr->next;
        }
    }
    return -1;
}