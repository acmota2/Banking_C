#include "dynamic_array.h"

DynamicArray* create_dynamic_array(size_t content_size, size_t n) {
    DynamicArray *r = calloc(1, sizeof(DynamicArray));
    r->array = malloc(content_size * n);
    return r;
}

inline void* access(DynamicArray *a, size_t i) {
    return a->array + (i * a->stride);
}

// as stack
bool push(DynamicArray *a, void const* elem) {
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

inline void *pop(DynamicArray *a) {
    if(a->length > 0) {
        return a->array + (a->length-- * a->stride);
    }
    return NULL;
}

inline void sort_by(DynamicArray *a, int (*compare)(void const*, void const*)) {
    qsort(a->array, a->length, a->stride, compare); // not standard, ver se pode ser assim
}
/*
void erase_position(DynamicArray *a, size_t index) {
    memset(a->array + (index * a->stride), 0, a->stride);
}
*/
void destroy_dynamic_array(DynamicArray *a, void (*destroyer)(void*)) {
    if(destroyer != NULL) {
        for(size_t i = 0; i < a->length; ++i) {
            destroyer(index_type(void *, a, i));
        }
    }
    free(a->array);
    free(a);
}