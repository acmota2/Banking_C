#include "lista_ligada.h"

Lista *create_lista() {
    return calloc(sizeof(Lista), 1);
}

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

// verifica ao mesmo tempo se o elemento existe na lista
bool remove(Lista *l, void *elem, bool (*equal)(void*, void*)) {
    Nodo *ptr = l->first;
    for(; ptr != NULL && equal(ptr->content, elem); ptr = ptr->next);
    if(ptr != NULL) {
        Nodo *prev = ptr->prev;
        prev->next = ptr->next;
        free(ptr);
        return true;
    }
    return false;
}

void destroy_lista(Lista *l, void (*destroyer)(void*)) {
    for(struct nodo **ptr = &l->first; ptr != NULL; *ptr = l->first) {
        // *ptr aqui é sempre o l->first, pelo que l->first->next == (*ptr)->next e so on
        if(destroyer != NULL) { // not sure se precisa disto
            destroyer((*ptr)->content);
        }
        l->first = (*ptr)->next;
        free(*ptr);
    }
    free(l);
}

// retorna NULL em caso do nodo não existir
Nodo *goto_nodo(Lista *l, size_t i) {
    if(i > l->length) {
        return NULL;
    }
    Nodo *n = l->first;
    for(; (i--) > 0; n = n->next);
    return n;
}

/*
void insert_ord() {

}
*/