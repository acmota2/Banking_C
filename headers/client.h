#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accounts.h"
#include "dynamic_array.h"

typedef struct client {
    unsigned long num_code;
    char *name;
    char *address;
    long global_balance;
    DynamicArray *accounts;
} Client;

Client create_client(unsigned long num_code, char *name, char *address);
bool client_exists(Client *c);
void edit_client_name(Client *c, char *new_name);
void edit_client_address(Client *c, char *new_address);
void add_account(Client *c, Account *a);
void erase_account(Client *c, size_t account_id);
void destroy_client(void *v);

#endif