#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_tui.h"
#include "funcs.h"


void op1 (int**bd){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JChoose which type of listing needed:\n");
        printf("1) Normal\n2) By location\n3) With negative balance\nQ) Quit\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
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
        default:
            break;
        }
    } while(*opt!='Q' && *opt!='q');
}