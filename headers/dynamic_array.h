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

#define index_type(type, array, i) ((type) access(array, i))
#define pop_type(type, array) ((type) pop(array))

DynamicArray* create_dynamic_array(size_t content_size, size_t n);
DynamicArray* create_dynamic_indextable(size_t content_size, size_t n);
inline void* access(DynamicArray *a, size_t i);
inline void* pop(DynamicArray *a);
bool push(DynamicArray *a, void const* elem);
inline void sort_by(DynamicArray *a, int (*compare)(void const*, void const*));
void erase_position(DynamicArray *a, size_t index);