#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_tui.h"
#include "funcs.h"

void op1_op1(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP1\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op1_op2(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP2\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op1_op3(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP3\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}



void op1 (int**bd){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JChoose which type of listing needed:\n");
        printf("1) Normal\n2) By location\n3) With negative balance\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
        switch (*opt){
            case '1':
                op1_op1();
                break;
            case '2':
                op1_op2();
                break;
            case '3':
                op1_op3();
                break;
            default:
                break;
        }
    } while(*opt!='Q' && *opt!='q');
}