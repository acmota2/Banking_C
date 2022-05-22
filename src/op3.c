#include "op3.h"

void op3(DynamicArray *bank){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JUnder construction\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}