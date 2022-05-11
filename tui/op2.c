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
                /* code */
                break;
            case '3':
                /* code */
                break;
            case '4':
                /* code */
                break;
            case '5':
                /* code */
                break;
            case '6':
                /* code */
                break;
            case '7':
                /* code */
                break;
            case '8':
                /* code */
                break;
            default:
                break;
        }
    } while(*opt!='Q' && *opt!='q');
}

void op2(int**bd){
    char name[1024] = {0};
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(name,1024,stdin);
    newline_to_nullt(name);
    op2_menu(name,bd);
}