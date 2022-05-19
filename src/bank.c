#include "bank.h"

/*
DISCLAIMER: o bank é um DynamicArray de clientes que estará na main, pelo
que não é necessário aparecer aqui numa struct, sendo gerido pela main
*/

static void tokenizer(char *base, char *token, char* str[], size_t n) {
    size_t i = 0;
    *str = base;
    // mudar para i <= n caso se verifique que o txt tenha ; no final
    for(char *aux = str[0]; i < n && strsep(&aux, token); str[i++] = aux);
}

void load_bank(DynamicArray *bank) {
    FILE *bank_f = fopen("./db/bank.txt", "r");
    char buffer[1024] = { 0 };
    for(char *buf_ptr = buffer; fgets(buf_ptr, 1024, bank_f);) {
        for(char *aux = buffer; strsep(&buf_ptr, ":"); aux = buf_ptr) {
            Client *c = NULL;
            Account *a = NULL;
            switch(*aux) {
                case 'C': {
                    char *arr[3] = { 0 };
                    tokenizer(buf_ptr, ";", arr, 3);
                    Client cl = create_client(
                        atol(arr[0]),
                        arr[1],
                        arr[2]
                    );
                    push(bank, &cl);
                    c = top(bank);
                    break;
                }
                case 'A': {
                    char *arr[4] = { 0 };
                    tokenizer(buf_ptr, ";", arr, 4);
                    Account ac = create_account(
                        atol(arr[0]),
                        *arr[2] == 'D' ? DEMAND : FIXED
                    );
                    ac.balance = atol(arr[1]),
                    push(c->accounts, &ac);
                    a = top(c->accounts);
                    break;
                }
                case 'M': {
                    char *arr[2] = { 0 };
                    tokenizer(buf_ptr, ";", arr, 2);
                    Movement m = (Movement) {
                        .amount = atol(arr[1])
                    };
                    memcpy(m.date, arr[0], sizeof("YYYY-MM-DD HH:MM:SS"));
                    break;
                }
                // casos de ID vazios
                case 'c': {
                    Client cl = { 0 };
                    push(bank, &cl);
                    break;
                }
                case 'a': {
                    Account ac = { 0 };
                    push(c->accounts, &ac);
                    break;
                }
                default:
                    break;
            }
        }
    }
    fclose(bank_f);
}

static int location_alphabetical(const void* ptr1, const void* ptr2) {
    Client client1 = *(Client *) ptr1;
    Client client2 = *(Client *) ptr2;
    return strcmp(client1.address, client2.address);
}

DynamicArray *clients_by_location(DynamicArray *clients) {
    DynamicArray *location = create_dynamic_array(sizeof(Client), 10);

    for(size_t i = 0; i < clients->length; ++i) {
        Client *current = index_type(Client *, clients, i);
        if(client_exists(current)) {
            push(location, current);
        }
    }
    sort_by(location, location_alphabetical);
    return location;
}

DynamicArray *clients_with_negative_balance(DynamicArray *clients) {
    DynamicArray *balance = create_dynamic_array(sizeof(Client), 10);

    for(size_t i = 0; i < clients->length; ++i) {
        Client *current = index_type(Client *, clients, i);
        if(client_exists(current) && current->global_balance < 0) {
            push(balance, current);
        }
    }
    return balance;
}

void erase_client(DynamicArray *bank, unsigned long id) {
    Client *c = index_type(Client *, bank, id);
    destroy_client(c);
}

void unload_bank(DynamicArray *bank) {
    FILE *bank_f = fopen("./db/bank.txt", "w");
    for(size_t i = 0; i < bank->length; ++i) {
        Client *c = index_type(Client *, bank, i);
        if(!client_exists(c)) {
            fputs("client erased\n", bank_f);
        } else {
                fprintf(
                    bank_f,
                    "Client:%zu;%s;%s\n",
                    c->num_code,
                    c->name,
                    c->address
                );
            for(size_t j = 0; j < c->accounts->length; ++j) {
                Account *a = index_type(Account *, c->accounts, j);
                if(!account_exists(a)) {
                    fputs("account erased\n", bank_f);
                } else {
                    fprintf(
                        bank_f,
                        "Account:%zu;%ld;%s\n",
                        a->code,
                        a->balance,
                        a->t == DEMAND ? "Demand" : "Fixed"
                    );
                    for(size_t k = 0; k < a->movements->length; ++k) {
                        Movement *m = index_type(Movement *, a->movements, k);
                        fprintf(
                            bank_f,
                            "Movement:%s;%ld\n",
                            m->date,
                            m->amount
                        );
                    }
                }
            }
        }
    }
    fclose(bank_f);
}