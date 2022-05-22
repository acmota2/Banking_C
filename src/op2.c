#include "op2.h"

void op2_op1(Client *c){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JInformation\n------------\nID: %zu\nName: %s\nAddress: %s\nNumber of accounts: %zu\n\nq) Go Back\n> ",c->num_code,c->name,c->address,c->accounts->length);
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op2(Client *c){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP2\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op3(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP3\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op4(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP4\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op5(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP5\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op6(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP6\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op7(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP7\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op8(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP8\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_menu(DynamicArray *bank,Client * c){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3J%s's account\n\nChoose an option:\n",c->name);
        printf("1) Show all information\n2) List all accounts\n3) Check a specific account\n4) Register money movement\n5) Check global position\n6) Edit a specific account\n7) Remove a specific account\n8) Create a new account\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        switch (*opt){
            case '1':
                op2_op1(c);
                break;
            case '2':
                op2_op2(c);
                break;
            case '3':
                op2_op3();
                break;
            case '4':
                op2_op4();
                break;
            case '5':
                op2_op5();
                break;
            case '6':
                op2_op6();
                break;
            case '7':
                op2_op7();
                break;
            case '8':
                op2_op8();
                break;
            default:
                break;
        }
    } while(*opt!='Q' && *opt!='q');
}

/*
    Nesta ação, pretende-se que o utilizador escreva o id do cliente e que devolva a informação e uma lista de ações
    Neste momento, basta escrever um nome e devolve esse nome. No futuro, irá-se verificar a existência desse ID.
*/

Client* getClient(DynamicArray *bank,char * id){
    size_t index = atol(id);
    if(index < bank->length){
        return access(bank,index); 
    } else {
        return NULL;
    }
}



void op2(DynamicArray *bank){
    char id[1024], opt[1024];
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);
    Client * c = getClient(bank,id);
    if(c !=NULL){
        if(client_exists(c)){
            op2_menu(bank,c);
        } else {
            do {
                printf("\e[H\e[2J\e[3JClient erased\nq) Go Back\n> ");
                fgets(opt,1024,stdin);
                newline_to_nullt(opt);
            } while(*opt!='Q' && *opt!='q');
        }
    } else {
        do {
            printf("\e[H\e[2J\e[3JInvalid ID\nq) Go Back\n> ");
            fgets(opt,1024,stdin);
            newline_to_nullt(opt);
        } while(*opt!='Q' && *opt!='q');
    }
}