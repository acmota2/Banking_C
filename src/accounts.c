#include "accounts.h"

/*
como só existem Account dentro dum array e este copia o conteúdo para si,
para evitar alocações desnecessárias na heap estes são retornados na stack
da função que chamar esta abaixo
*/
Account create_account(unsigned long code, Type t) {
    return (Account) {
        .code = code,
        .t = t,
        .movements = create_dynamic_array(sizeof(Movement), 10)
    };
}

bool account_exists(Account *a) {
    return a->movements != NULL;
}

void add_movement(Account *a ,Movement *m) {
    a->balance += m->amount;
    push(a->movements, m);
}
/*
se necessário
void erase_movement(unsigned long id , Account *a) {
    erase_position(a->movements, id);
}
*/
void destroy_account(void *v) {
    Account *a = v;
    if(account_exists(a)) {
        destroy_dynamic_array(a->movements, NULL);
        a->movements = NULL; // sanity checking
    }
}