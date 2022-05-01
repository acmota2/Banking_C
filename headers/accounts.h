#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Type kind; 
} Account;