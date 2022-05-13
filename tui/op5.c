#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_tui.h"
#include "funcs.h"


void create_user(){
    char name[1024];
    char address[1024];
    char opt[1024];

    puts("\e[H\e[2J\e[3JSet name:");
    fgets(name,1024,stdin);
    newline_to_nullt(name);

    puts("\e[H\e[2J\e[3JSet address:");
    fgets(address,1024,stdin);
    newline_to_nullt(address);
    
    do {
        printf("\e[H\e[2J\e[3JName:%s\nAddress:%s\n\nQ) Go Back\n> ",name,address);
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op5(int**bd){
    create_user();
}