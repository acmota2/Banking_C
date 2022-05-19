#include "op1.h"


void op1_list(DynamicArray *bank,int op){
    char opt[1024];
    switch(op){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    do {
        printf("\e[H\e[2J\e[3J%d\n\nq) Go Back\n> ",op);
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op1 (DynamicArray *bank){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JChoose which type of listing needed:\n");
        printf("1) Normal\n2) By location\n3) With negative balance\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
        switch (*opt){
            case '1':
                op1_list(bank,1);
                break;
            case '2':
                op1_list(bank,2);
                break;
            case '3':
                op1_list(bank,3);
                break;
            default:
                break;
        }
    } while(*opt!='Q' && *opt!='q');
}