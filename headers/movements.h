#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum movement_type {
    CREDIT,
    DEBIT
} MovementType;

typedef struct movement {
    char date[sizeof("YYYY-MM-DD HH:MM:SS")];
    MovementType t;
    long amount;
} Movement;

Movement make_movement(long amount, MovementType t);

#endif