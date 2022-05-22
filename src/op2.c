#include "op2.h"

void op2_op1(DynamicArray* bank, Client *c){
    char opt[1024];
    do {
        size_t i = (size_t) c->num_code;
        calculate_global_balance(bank,i);
        printf("\e[H\e[2J\e[3JInformation\n------------\nID: %zu\nName: %s\nAddress: %s\nGlobal Balance:%g \nNumber of accounts: %zu\n\nq) Go Back\n> ",c->num_code,c->name,c->address,c->global_balance / 100.,c->accounts->length);
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void print_list_accounts(Client * c){
    size_t length = c->accounts->length;
    if(length == 0){
        printf("The client doesn't have any accounts!\n");
    } else {
        for(size_t i=0;i<length;i++){
            Account * a = access(c->accounts,i);
            if(!account_exists(a)){
                printf("[Account erased]\n");
            } else {
                size_t mlength = a->movements->length;
                char *ta = a->t == FIXED ? "FIXED" : "DEMAND";

                printf("[ID]:%zu [Type of account]:%s [Number of movements]:%zu\n\nMovements:\n",a->code,ta,mlength);
                char *type;
                for(size_t j=0;j<mlength;j++){
                    Movement* m = access(a->movements,j); 
                    type = m->t == CREDIT ? "CREDIT" : "DEBIT";
                    printf("[Date]:%s [Type of Movement]:%s [Amount]:%g \n",m->date,type,m->amount / 100.);
                }
            }
            printf("------------\n");
        }
    }
}


void op2_op2(Client *c){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3J");
        print_list_accounts(c);
        printf("q) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}




void op2_op3(Client *c){
    char id[1024],opt[1024];
    printf("\e[H\e[2J\e[3JID of the account:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);

    size_t index = atol(id);
    if(index < c->accounts->length){
        Account * a = access(c->accounts,index);
        if(account_exists(a)){
            do {
                printf("\e[H\e[2J\e[3J");
                size_t mlength = a->movements->length;
                char *ta = a->t == FIXED ? "FIXED" : "DEMAND";
                printf("[ID]:%zu [Type of account]:%s [Number of movements]:%zu\n\nMovements:\n",a->code,ta,mlength);
                char *type;
                for(size_t j=0;j<mlength;j++){
                    Movement* m = access(a->movements,j); 
                    type = m->t == CREDIT ? "CREDIT" : "DEBIT";
                    printf("[Date]:%s [Type of Movement]:%s [Amount]:%g \n",m->date,type,m->amount / 100.);
                }
                printf("\nq) Go Back\n> ");
                fgets(opt,1024,stdin);
                newline_to_nullt(opt);
            } while(*opt!='Q' && *opt!='q');
        } else {
            do {
                printf("\e[H\e[2J\e[3JAccount doesn't exist anymore\nq) Go Back\n> ");
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

void op2_op4(Client * c){
    char type[1024],id[1024], opt[1024],amount[1024];
    


    printf("\e[H\e[2J\e[3JID of the account:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);

    Account * a;
    size_t index = atol(id);
    if(index < c->accounts->length){
        a = access(c->accounts,index); 
    } else {
        a = NULL;
    }

    if(a !=NULL){
        if(account_exists(a)){
            printf("\e[H\e[2J\e[3JAmount of money:\n");
            fgets(amount,1024,stdin);
            newline_to_nullt(amount);

            do {
                puts("\e[H\e[2J\e[3JSet type of movement[CREDIT|DEBIT]:");
                fgets(type,1024,stdin);
                newline_to_nullt(type);
            } while(!strcmp(type,"CREDIT") && !strcmp(type,"DEBIT"));
            
            MovementType t = *type == 'C' ? CREDIT : DEBIT;

            Movement m = make_movement(atol(amount),t);
            add_movement(a,&m);

            do {
                printf("\e[H\e[2J\e[3JMovement added successfully!\nq) Go Back\n> ");
                fgets(opt,1024,stdin);
                newline_to_nullt(opt);
            } while(*opt!='Q' && *opt!='q');
        } else {
            do {
                printf("\e[H\e[2J\e[3JAccount already erased\nq) Go Back\n> ");
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


void op2_op5(){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JUnder construction\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_op6(Client * c){
    char id[1024], opt[1024];
    printf("\e[H\e[2J\e[3JID of the account:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);
    Account * a;
    size_t index = atol(id);
    if(index < c->accounts->length){
        a = access(c->accounts,index); 
    } else {
        a = NULL;
    }

    if(a !=NULL){
        if(account_exists(a)){
            erase_account(c,a->code);
            do {
                printf("\e[H\e[2J\e[3JAccount erased successfully!\nq) Go Back\n> ");
                fgets(opt,1024,stdin);
                newline_to_nullt(opt);
            } while(*opt!='Q' && *opt!='q');
        } else {
            do {
                printf("\e[H\e[2J\e[3JAccount already erased\nq) Go Back\n> ");
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

void op2_op7(Client *c){
    char type[1024];

    do {
        puts("\e[H\e[2J\e[3JSet type[DEMAND|FIXED]:");
        fgets(type,1024,stdin);
        newline_to_nullt(type);
    } while(!strcmp(type,"FIXED") && !strcmp(type,"DEMAND"));
    
    Type t = *type == 'F' ? FIXED : DEMAND;
    Account a = create_account(c->accounts->length,t);
    add_account(c,&a);


    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3JAccount created successfully!\n\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        newline_to_nullt(opt);
    } while(*opt!='Q' && *opt!='q');
}

void op2_menu(DynamicArray *bank,Client * c){
    char opt[1024];
    do {
        printf("\e[H\e[2J\e[3J%s's account\n\nChoose an option:\n",c->name);
        printf("1) Show all information\n2) List all accounts\n3) Check a specific account\n4) Register money movement\n5) Edit a specific account\n6) Remove a specific account\n7) Create a new account\nq) Go Back\n> ");
        fgets(opt,1024,stdin);
        switch (*opt){
            case '1':
                op2_op1(bank,c);
                break;
            case '2':
                op2_op2(c);
                break;
            case '3':
                op2_op3(c);
                break;
            case '4':
                op2_op4(c);
                break;
            case '5':
                op2_op5();
                break;
            case '6':
                op2_op6(c);
                break;
            case '7':
                op2_op7(c);
                break;
            default:
                break;
        }
    } while(*opt!='Q' && *opt!='q');
}

/*
    Nesta ação, pretende-se que o utilizador escreva o id do cliente e que devolva a informação e uma lista de ações
    Neste momento, basta escrever um nome e devolve esse nome.
*/

void op2(DynamicArray *bank){
    char id[1024], opt[1024];
    printf("\e[H\e[2J\e[3JID of the client:\n");
    fgets(id,1024,stdin);
    newline_to_nullt(id);
    Client * c = get_client(bank,id);
    if(c !=NULL){
        if(client_exists(c)){
            op2_menu(bank,c);
        } else {
            do {
                printf("\e[H\e[2J\e[3JClient doesn't exist anymore\nq) Go Back\n> ");
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