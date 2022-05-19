#include "utils_tui.h"

/*
    Quando o utilizador escreve um input, o \n fica quando se executa a função "fgets". 
    Com esta função, garantimos que apenas fica a string sem esse \n extra.
*/
void newline_to_nullt (char * sub){
    char* ni = strchr(sub,'\n');
    if(ni != NULL){
        *ni = '\0';
    }
}