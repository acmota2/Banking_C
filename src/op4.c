#include "op4.h"

void op4(DynamicArray *bank){
    char id[1024], opt[1024];
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);
    Client * c = get_client(bank,id);
    if(c !=NULL){
        if(client_exists(c)){
            erase_client(bank,c->num_code);
            do {
                printf("\e[H\e[2J\e[3JClient erased successfully!\nq) Go Back\n> ");
                fgets(opt,1024,stdin);
                newline_to_nullt(opt);
            } while(*opt!='Q' && *opt!='q');
        } else {
            do {
                printf("\e[H\e[2J\e[3JClient already erased\nq) Go Back\n> ");
                fgets(opt,1024,stdin);
                newline_to_nullt(opt);
            } while(*opt!='Q' && *opt!='q');
        }
    } else {
        do {
            printf("\e[H\e[2J\e[3JInvalid ID\nq) Go Back\n> ");
            fgets(opt,1024,stdin);
            newline_to_nullt(opt);
        } while(*opt!='Q' && *opt!='q');
    }
}