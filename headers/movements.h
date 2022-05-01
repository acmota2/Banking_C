#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum movement_type {
    CREDIT,
    DEBIT
} MovementType;

typedef struct movement {
    char date[sizeof("YYYY-MM-DD HH:MM:SS")];
    MovementType mov;
    long ammount;
} Movement;