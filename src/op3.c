#include "op3.h"

void op3(DynamicArray * bank){
    char id[1024], opt[1024];
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);
    Client * c = get_client(bank,id);
    if(c !=NULL){
        if(client_exists(c)){
            
            char name[1024];
            char address[1024];

            printf("\e[H\e[2J\e[3JSet name[%s]:\n",c->name);
            fgets(name,1024,stdin);
            newline_to_nullt(name);
            edit_client_name(c,name);

            printf("\e[H\e[2J\e[3JSet address[%s]:\n",c->address);
            fgets(address,1024,stdin);
            newline_to_nullt(address);
            edit_client_address(c,address);

            do {
                printf("\e[H\e[2J\e[3JClient edited successfully!\nq) Go Back\n> ");
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