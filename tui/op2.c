#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_tui.h"
#include "funcs.h"

void op2_op1(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JInformation\n------------\n\nName: Any Name\nAddress: 22 Fake Street\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op2(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP2\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op3(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP3\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op4(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP4\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op5(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP5\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op6(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP6\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op7(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP7\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op8(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP8\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_menu(char*name,int**bd){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3J%s's account\n\nChoose an option:\n",name);
        printf("1) Show all information\n2) List all accounts\n3) Check a specific account\n4) Register money movement\n5) Check global position\n6) Edit a specific account\n7) Remove a specific account\n8) Create a new account\nQ) Go Back\n> ");
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

void op2(int**bd){
    char name[1024];
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(name,1024,stdin);
    newline_to_nullt(name);
    op2_menu(name,bd);
}