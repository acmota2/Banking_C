#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accounts.h"

typedef struct account_list {
    
} AccountList;

typedef struct client {
    unsigned long num_code;
    long global_balance;
    Account *accounts;
    char *name;
    char *address;
} Client;