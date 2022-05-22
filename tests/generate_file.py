import random

def generate_file():
    random.seed(a=None, version=2)
    
    with open('../db/names.txt') as in_f:
        names = in_f.read().splitlines()

        x = input('Numero: ')
        with open('./db/parse_test.txt', 'w') as out_f:
            lines = []
            numero_casas = random.randint(850, 1150)
            for i in range(0, numero_casas):
                

def generate_name(names):    
    

if __name__ == __main__:
    generate_file