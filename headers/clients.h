#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accounts.h"
#include "lista_ligada.h"

typedef struct client {
    unsigned long num_code;
    long global_balance;
    Lista *accounts;
    char *name;
    char *address;
} Client;