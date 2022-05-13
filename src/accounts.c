#include "accounts.h"

Account *create_account() {
    Account *r = calloc(1, sizeof(Account));
    if(r != NULL) {
        r->movements = create_dynamic_array(sizeof(Movement), 10);
    }
    return r;
}

bool add_movement(Account *a ,Movement *m) {
    a->balance += m->amount;
    return push(a->movements, m);
}

void erase_movement(unsigned long id , Account *a) {
    erase_position(a->movements, id);
}

void destroy_account(Account *a) {
    destroy_dynamic_array(a->movements, NULL);
    free(a);
}