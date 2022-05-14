#include "accounts.h"

Account create_account(unsigned long code, Type t) {
    return (Account) {
        .code = code,
        .t = t,
        .movements = create_dynamic_array(sizeof(Movement), 10)
    };
}

bool add_movement(Account *a ,Movement *m) {
    a->balance += m->amount;
    return push(a->movements, m);
}
/*
se necessário
void erase_movement(unsigned long id , Account *a) {
    erase_position(a->movements, id);
}
*/
void destroy_account(Account *a) {
    destroy_dynamic_array(a->movements, NULL);
    a->movements = NULL; // sanity checking
}