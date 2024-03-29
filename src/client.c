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

void add_account(Client *c, Account *a) {
    c->global_balance += a->balance;
    push(c->accounts, a);
}

void edit_client_name(Client *c, char *new_name) {
    free(c->name);
    c->name = strdup(new_name);
}

void edit_client_address(Client *c, char *new_address) {
    free(c->address);
    c->address = strdup(new_address);
}

void erase_account(Client *c, unsigned long account_id) {
    Account *a = index_type(Account *, c->accounts, account_id);
    c->global_balance -= a->balance;
    destroy_account(a);
}

void destroy_client(void *v) {
    Client *c = v;
    if(client_exists(c)) {
        if(c->accounts->length == 0) {
            destroy_dynamic_array(c->accounts, NULL);
        } else {
            destroy_dynamic_array(c->accounts, destroy_account);
        }
        free(c->name);
        c->name = NULL;
        free(c->address);
        c->address = NULL;
    }
}