#include "op1.h"

void print_list(DynamicArray *bank){
    for(size_t i = 0; i < bank->length; ++i) {
        Client *c = index_type(Client *, bank, i);
        if(!client_exists(c)) {
            printf("client erased\n");
        } else {
                printf(
                    "[Id]:%zu [Name]:%s [Address]:%s\n",
                    c->num_code,
                    c->name,
                    c->address
                );
        }
    }
}


void op1_list(DynamicArray *bank,int op){
    char opt[1024];
    DynamicArray * bank_print;
    switch(op){
        case 1:
            bank_print = bank;
            break;
        case 2:
            bank_print = clients_by_location(bank);
            break;
        case 3:
            bank_print = clients_with_negative_balance(bank);
            break;
        default:
            break;
    }
    do {
        printf("\e[H\e[2J\e[3J");
        print_list(bank_print);
        printf("\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op1 (DynamicArray *bank){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JChoose which type of listing needed:\n");
        printf("1) Normal\n2) By location\n3) With negative balance\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
        switch (*opt){
            case '1':
                op1_list(bank,1);
                break;
            case '2':
                op1_list(bank,2);
                break;
            case '3':
                op1_list(bank,3);
                break;
            default:
                break;
        }
    } while(*opt!='Q' && *opt!='q');
}