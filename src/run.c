#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bank.h"
#include "op1.h"
#include "op2.h"
#include "op3.h"
#include "op4.h"
#include "op5.h"
#include "utils_tui.h"

/*
    \e[H\e[2J\e[3J -> limpa o terminar, tal como funciona a system call "clear"
    
    A função lê e coordena a ação que o utilizador pretende realizar
*/
void main_menu(DynamicArray *bank) {
    char opt[1024];
    do {
        puts("\e[H\e[2J\e[3JWelcome to Banksie!\n\nChoose an option:");
        printf("1) List all clients\n2) Check a specific client\n3) Edit a specific client\n4) Remove a specific client\n5) Create a new client\nq) Quit\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
        switch (opt[0]){
            case '1':
                op1(bank);
                break;
            case '2':
                op2(bank);
                break;
            case '3':
                op3(bank);
                break;
            case '4':
                op4(bank);
                break;
            case '5':
                op5(bank);
                break;
            default:
                break;
        }
    } while(opt[0]!='Q' && opt[0]!='q');
    printf("[EXITED]\n");
}

/*
    Executa a função "main_menu", mas tenciona-se inicializar e dar free à estrutura de dados nesta função 
*/
void run (){
    DynamicArray *bank = create_dynamic_array(sizeof(Client), 0);
    load_bank(bank);
    main_menu(bank);
    unload_bank(bank);
    destroy_dynamic_array(bank, destroy_client);
}

/*
    Apenas executa a função "run"
*/
int main(void){
    run();
    return 0;
}