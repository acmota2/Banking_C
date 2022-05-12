#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_tui.h"
#include "funcs.h"

void op4(int**bd){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JOP4\n\nQ) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}