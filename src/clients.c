#include "clients.h"
#include "dynamic_array.h"

static int date_is_bigger_than(const void* ptr1, const void* ptr2) {
    Client client1 = *(Client *) ptr1;
    Client client2 = *(Client *) ptr2;
    return strcmp(client1.address, client2.address);
}

DynamicArray *clients_by_location(DynamicArray *clients) {
    DynamicArray *location = 
}