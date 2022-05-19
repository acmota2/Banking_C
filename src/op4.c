#include "op4.h"

void op4(DynamicArray *bank){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP4\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}