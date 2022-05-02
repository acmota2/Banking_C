#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    void *content;
    struct nodo *next;
    struct nodo *prev;
} Nodo;

typedef struct lista {
    size_t length;
    Nodo *first;
    Nodo *last;
} Lista;

void append(Lista *l, void *elem);
void prepend(Lista *l, void *elem);
bool remove(Lista *l, void *elem, bool (*equal)(void*, void*));
void destroy_lista(Lista *l, void (*destroyer)(void*));
Nodo *goto_nodo(Lista *l, size_t i);