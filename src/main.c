#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bank.h"

int main(int argc, char *argv[]) {
    DynamicArray *bank = create_dynamic_array(sizeof(Client), 0);

    destroy_dynamic_array(bank, destroy_client);
}