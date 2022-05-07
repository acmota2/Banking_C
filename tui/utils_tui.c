#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void newline_to_nullt (char * sub){
    char* ni = strchr(sub,'\n');
    if(ni != NULL){
        *ni = '\0';
    }
}