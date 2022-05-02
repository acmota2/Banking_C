#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    size_t length;
    struct nodo *first;
    struct nodo *last;
} Lista;

typedef struct nodo {
    void *content;
    struct nodo *next;
} Nodo;

void append(Lista *l, void *elem) {
    Nodo *new = malloc(sizeof(Nodo));
    new->next = NULL;
    new->content = elem;
    l->last = new;
}

void prepend(Lista *l, void *elem) {
    Nodo *new = malloc(sizeof(Nodo));
    new->next = l->first;
    new->content = elem;
    l->first = new;
}

/*
void insert_ord() {

}
*/