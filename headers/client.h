#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accounts.h"
#include "dynamic_array.h"

typedef struct client {
    unsigned long num_code;
    long global_balance;
    DynamicArray *accounts;
    char *name;
    char *address;
} Client;

Client create_client(unsigned long num_code, char *name, char *address);
bool client_exists(Client *c);
bool add_account(Client *c, Account *a);
void erase_account(Client *c, size_t account_id);
void destroy_client(Client *c);

#endif