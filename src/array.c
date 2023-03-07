#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
	int *array;
	int size;
	int capacity;
} Array;

Array new_array(int capacity) {
    if(capacity < 1) {
        printf("Capacity must be at least 1!");
        exit(EXIT_FAILURE);
    }
	Array array;
	// Create an array of integers with a custom capacity
	array.array = malloc(capacity * sizeof(int));
	array.size = 0;
	array.capacity = capacity;

	return array;
}

void array_resize(Array *array, int capacity) {
	int *new_array;
	new_array = malloc(capacity * sizeof(int));
	for(int i = 0; i < array->size; i++) {
		new_array[i] = array->array[i];
	}
	free(array->array);
	array->array = new_array;
}

void array_add(Array *array, int item) {
	if(array->size == array->capacity) {
		array_resize(array, array->capacity*2);
	}
	array->array[array->size] = item;
	array->size++;
}

void array_del(Array *array, int index) {
	if(index >= array->size || index < 0) {
		printf("Error, index out of bonds\n.");
		exit(EXIT_FAILURE);
	}
	if((array->capacity/4) == array->size) {
		array_resize(array, array->capacity);
	}
    for(int i = index; i < array->size; i++) {
        if(i == array->size-1) {
            break;
        }
        array->array[i] = array->array[i+1];
    }
    array->size--;
}

int array_find(Array *array, int value) {
    for(int i = 0; i < array->size; i++) {
        if(array->array[i] == value) {
            return i;
        }
    }
    return -1;
}

int array_get(Array *array, int index) {
	if(index >= array->size || index < 0) {
		printf("Error, index out of bonds\n.");
		exit(EXIT_FAILURE);
	}
	return array->array[index];
}

int array_size(Array *array) {
    return array->size;
}