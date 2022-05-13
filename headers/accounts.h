#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"
#include "movements.h"
/*
ABSTRACT:

Como se pretende completa edição das contas do banco, usar-se-á uma lista ligada para estas
*/

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

Account *create_account(void);
bool add_movement(Account *a ,Movement *m);
void erase_movement(unsigned long id , Account *a);
void destroy_account(Account *a);