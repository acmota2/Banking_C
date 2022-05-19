#include "op5.h"


void create_user(DynamicArray *bank){
    char name[1024];
    char address[1024];
    char opt[1024];

    puts("\e[H\e[2J\e[3JSet name:");
    fgets(name,1024,stdin);
    newline_to_nullt(name);

    puts("\e[H\e[2J\e[3JSet address:");
    fgets(address,1024,stdin);
    newline_to_nullt(address);

    Client new_client = create_client(bank->length,name,address);
    push(bank,&new_client);
    
    do {
        printf("\e[H\e[2J\e[3JCreated with success\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op5(DynamicArray *bank){
    create_user(bank);
}