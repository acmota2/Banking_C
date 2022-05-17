#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"
#include "client.h"

DynamicArray *clients_by_location(DynamicArray *clients);
DynamicArray *clients_with_negative_balance(DynamicArray *clients);