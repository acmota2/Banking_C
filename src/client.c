#include "client.h"

Client *create_client() {
    Client *r = calloc(1, sizeof(Client));
    r->accounts = create_dynamic_array(sizeof(Account), 0);
    return r;
}

bool add_account(Client *c, Account *a) {
    c->global_balance += a->balance;
    return push(c->accounts, a);
}

void erase_account(Client *c, size_t account_id) {
    Account *a = index_type(Account *, c->accounts, account_id);
    c->global_balance -= a->balance;
    destroy_account(a);
    erase_position(c->accounts, account_id);
}

void destroy_client(Client *c) {
    destroy_dynamic_array(c->accounts, destroy_account);
    free(c);
}