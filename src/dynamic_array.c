#include "dynamic_array.h"

DynamicArray* create_dynamic_array(size_t content_size, size_t n) {
    DynamicArray *r = malloc(sizeof(DynamicArray));
    r->capacity = n == 0 ? 1 : n;
    r->length = 0;
    r->stride = content_size;
    r->array = malloc(content_size * r->capacity);
    return r;
}

void* access(DynamicArray *a, size_t i) {
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
        a->array + (a->length * a->stride),
        elem,
        a->stride
    );
    ++a->length;
    return true;
}

void *pop(DynamicArray *a) {
    if(a->length > 0) {
        return a->array + (a->length-- * a->stride);
    }
    return NULL;
}

void *top(DynamicArray *a) {
    return a->array + ((a->length - 1) * a->stride);
}

void sort_by(DynamicArray *a, int (*compare)(void const*, void const*)) {
    // ver se pode ser assim
    qsort(a->array, a->length, a->stride, compare);
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
/*
// this probably wasn't necessary
void read_file_to_array(FILE *f, DynamicArray *a) {
    for(
        void *buf = malloc(a->stride); 
        fread(buf, a->stride, 1, f) > 0;
        push(a, buf)
    );
}

bool write_array_to_file(FILE *f, DynamicArray *a) {
    size_t written = fwrite(a->array, 1, a->length * a->stride, f);
    return written == a->length;
}
*/
// TESTING

/*
struct teste {
    char *str;
};

void destroy_teste(void *v) {
    struct teste *t = v;
    free(t->str);
}

int main(int argc, char *argv[]) {
    DynamicArray *strs = create_dynamic_array(sizeof(struct teste), argc - 1);

    for(size_t i = 1; i < argc; ++i) {
        puts(argv[i]);
        push(strs, &(struct teste){ .str = strdup(argv[i]) });
        puts(index_type(struct teste *, strs, i - 1)->str);
    }

    destroy_dynamic_array(strs, destroy_teste);
}
*/