#ifndef BANK_H
#define BANK_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"
#include "client.h"

void load_bank(DynamicArray *bank);
DynamicArray *clients_by_location(DynamicArray *clients);
DynamicArray *clients_with_negative_balance(DynamicArray *clients);
Client* getClient(DynamicArray *bank,char * id);
void erase_client(DynamicArray *bank, unsigned long id);
void unload_bank(DynamicArray *bank);

#endif