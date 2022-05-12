#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op1.h"
#include "op2.h"
#include "op3.h"
#include "op4.h"
#include "op5.h"
#include "utils_tui.h"
#include "funcs.h"

void main_menu(int**bd) {
    char opt[1024];
    do {
        puts("\e[H\e[2J\e[3JWelcome to Banksie!\n\nChoose an option:");
        printf("1) List all clients\n2) Check a specific client\n3) Edit a specific client\n4) Remove a specific client\n5) Create a new client\nQ) Quit\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
        switch (opt[0]){
            case '1':
                op1(bd);
                break;
            case '2':
                op2(bd);
                break;
            case '3':
                op3(bd);
                break;
            case '4':
                op4(bd);
                break;
            case '5':
                op5(bd);
                break;
            default:
                break;
        }
    } while(opt[0]!='Q' && opt[0]!='q');
    printf("[EXITED]\n");
}



void run (){
    int*bd;
    load(&bd,5);
    main_menu(&bd);
    clear(bd);
}

int main(void){
    run();
    return 0;
}