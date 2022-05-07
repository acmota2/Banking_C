#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load(int ** arr,int len){
    *arr = malloc(len * sizeof(int));
    if(*arr == NULL)
        return;
    for(size_t i=0;i<len;i++)
        (*arr)[i] = 0;
}

void print(int ** arr,int len){
    for(size_t i=0;i<len;i++){
        printf("%d",(*arr)[i]);
    }
    printf("\n");
}

void clear(int *bd){
    free(bd);
}