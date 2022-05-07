#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_tui.h"
#include "funcs.h"

void op2_menu(char*name,int**bd){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3J%s's account\n",name);
        printf("OP2\n> ");
        fgets(opt,1024,stdin);
        switch (*opt){
            case '1':
                /* code */
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