#include "bank.h"

/*
DISCLAIMER: o bank é um DynamicArray de clientes que à partida estará na main, pelo
que não é necessário aparecer aqui numa struct ou assim, sendo gerido pela main
*/

static int location_alphabetical(const void* ptr1, const void* ptr2) {
    Client client1 = *(Client *) ptr1;
    Client client2 = *(Client *) ptr2;
    return strcmp(client1.address, client2.address);
}

DynamicArray *clients_by_location(DynamicArray *clients) {
    DynamicArray *location = create_dynamic_array(sizeof(Client), 10);

    for(size_t i = 0; i < clients->length; ++i) {
        Client *current = index_type(Client *, clients, i);
        if(client_exists(current)) {
            push(location, current);
        }
    }
    
    sort_by(location, location_alphabetical);
    return location;
}

DynamicArray *clients_with_negative_balance(DynamicArray *clients) {
    DynamicArray *balance = create_dynamic_array(sizeof(Client), 10);

    for(size_t i = 0; i < clients->length; ++i) {
        Client *current = index_type(Client *, clients, i);
        if(client_exists(current) && current->global_balance < 0) {
            push(balance, current);
        }
    }

    return balance;
}

void erase_client(DynamicArray *bank, unsigned long id) {
    Client *c = index_type(Client *, bank, id);
    destroy_client(c);
}