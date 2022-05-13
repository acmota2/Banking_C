#include "clients.h"
#include "dynamic_array.h"

static int location_alphabetical(const void* ptr1, const void* ptr2) {
    Client client1 = *(Client *) ptr1;
    Client client2 = *(Client *) ptr2;
    return strcmp(client1.address, client2.address);
}

DynamicArray *clients_by_location(DynamicArray *clients) {
    DynamicArray *location = create_dynamic_indextable(sizeof(Client), 10);
    
    for(size_t i = 0; i < clients->length; ++i) {
        Client *current = index_type(Client *, clients, i);
        if(current->name != '\0') {
            push(location, current);
        }
    }
    
    sort_by(location, location_alphabetical);
    return location;
}

DynamicArray *clients_with_negative_balance(DynamicArray *clients) {
    DynamicArray *balance = create_dynamic_indextable(sizeof(Client), 10);
    
    for(size_t i = 0; i < clients->length; ++i) {
        Client *current = index_type(Client *, clients, i);
        if(current->global_balance < 0) {
            push(balance, current);
        }
    }
    
    return balance;
}