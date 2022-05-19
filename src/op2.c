#include "op2.h"

void op2_op1(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JInformation\n------------\n\nName: Any Name\nAddress: 22 Fake Street\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op2(){
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

void op2_menu(DynamicArray *bank,char*name){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3J%s's account\n\nChoose an option:\n",name);
        printf("1) Show all information\n2) List all accounts\n3) Check a specific account\n4) Register money movement\n5) Check global position\n6) Edit a specific account\n7) Remove a specific account\n8) Create a new account\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        switch (*opt){
            case '1':
                op2_op1();
                break;
            case '2':
                op2_op2();
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
void op2(DynamicArray *bank){
    char name[1024];
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(name,1024,stdin);
    newline_to_nullt(name);
    op2_menu(bank,name);
}