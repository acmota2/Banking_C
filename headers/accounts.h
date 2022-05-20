#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"
#include "movements.h"

typedef enum type {
    DEMAND, // prazo
    FIXED   // ordem
} Type;

typedef struct account {
    unsigned long code;
    long balance;
    Type t;
    DynamicArray *movements;
} Account;

Account create_account(unsigned long code, Type t);
bool add_movement(Account *a ,Movement *m);
bool account_exists(Account *a);
void erase_movement(unsigned long id , Account *a);
void destroy_account(void *v);

#endif