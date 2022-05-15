#include "client.h"

/*
como só existem Client dentro dum array e este copia o conteúdo para si,
para evitar alocações desnecessárias na heap estes são retornados na stack
da função que chamar esta abaixo
*/
Client create_client(unsigned long num_code, char *name, char *address) {
    return (Client) {
        .num_code = num_code,
        .accounts = create_dynamic_array(sizeof(Account), 0),
        .name = strdup(name),
        .address = strdup(address)
    };
}

bool client_exists(Client *c) {
    return c->name != NULL;
}

bool add_account(Client *c, Account *a) {
    c->global_balance += a->balance;
    return push(c->accounts, a);
}

void erase_account(Client *c, unsigned long account_id) {
    Account *a = index_type(Account *, c->accounts, account_id);
    c->global_balance -= a->balance;
    destroy_account(a);
}

void destroy_client(Client *c) {
    destroy_dynamic_array(c->accounts, destroy_account);
    free(c->name);
    c->name = NULL;
    free(c->address);
    c->address = NULL;
}