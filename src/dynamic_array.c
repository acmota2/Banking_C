#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynamic_array {
    size_t length;
    size_t capacity;
    size_t stride;
    unsigned char *array;
} DynamicArray;

bool pop(DynamicArray *a, void const* elem) {
    if(a->length == a->capacity) {
        void *confirm = realloc(a->array, a->capacity *= 2);
        if(confirm == NULL) {
            return false;
        }
    }
    memcpy(
        a->array + (++a->length * a->stride),
        elem,
        a->stride
    );
    return true;
}

void *push(DynamicArray *a) {
    return a->array + (a->length-- * a->stride);
}