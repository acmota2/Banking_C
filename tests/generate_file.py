import random
from random import randint as rint
import datetime

tipos_ruas = [
    'Rua',
    'Avenida',
    'Travessa',
    'Largo',
    'Praça'
]

nomes = ['Abel', 'Abilio', 'Ana', 'Anacleto', 'Andre', 'Antonio', 'Beatriz', 'Bernardete', 'Bernardo', 'Carolina', 'Catarina', 'Carlos', 'Carlota', 'Diana', 'Diogo', 'Dinis', 'Dionisio', 'Eva', 'Eliseu', 'Eusebio', 'Fernando', 'Galileu', 'Hugo', 'Joao', 'Joaquim', 'Jose', 'Julio', 'Luis', 'Madalena', 'Margarida', 'Matilde', 'Simao', 'Simone', 'Rita', 'Rui', 'Vasco', 'Vera', 'Viriato', 'Zacarias', 'Zelia']

apelidos = ['Albuquerque', 'Antunes', 'Araujo', 'Barbosa', 'Berardo', 'Bettencourt', 'Camoes', 'Carvalho', 'Cerqueira', 'Coelho', 'Costa', 'Dias', 'Fernandes', 'Ferreira', 'Henriques', 'Lino', 'Lopes', 'Machado', 'Martins', 'Mota', 'Nunes', 'Osorio', 'Oliveira', 'Pereira', 'Pina', 'Pinto', 'Pinho', 'Rebelo', 'Reis', 'Rodrigues', 'Sa', 'Saramago', 'Sousa', 'Vasques', 'Vaz', 'Veloso']

def generate_file():
    random.seed(a=127634, version=2)

    x = input('Nome para um ficheiro txt: ')
    with open('./db/' + x + '.txt', 'w+') as out_f:
        lines = []
        clientes = rint(850, 1150)
        for i in range(0, clientes):
            lines.append('Client:' + str(i) + ';' + generate_name() + ';' + generate_address() + '\n')

            contas = rint(1, 4)
            generate_accounts(contas, lines)
        
        out_f.write(''.join(lines))

def generate_address():
    return str(tipos_ruas[rint(0, len(tipos_ruas) - 1)]) + ' ' + generate_name()

def generate_accounts(contas, lines):
    for i in range(0, contas):
        account_type = 'Demand' if rint(0, 1) == 1 else 'Fixed'
        ammount = generate_movements(account_type, lines)
        lines.append('Account:' + str(i) + ';' + str(ammount) + ';' + account_type + '\n')

def generate_movements(ac_type, lines):
    balance = 0
    now = datetime.datetime.now()
    for i in range(0, rint(1, 8)):
        then = now + datetime.timedelta(days=i, hours=rint(0,i))
        ammount = rint(-30000, 30000)
        lines.append('Movement:' + ';' + then.strftime('%Y-%m-%d %H:%M:%S') + ';' + str(ammount) + ';' + ac_type + '\n')
        balance += ammount
    return balance

def generate_name():
    return nomes[rint(0, len(nomes) - 1)] + ' ' + apelidos[rint(0, len(apelidos) - 1)]

def __main__():
    generate_file()

if __name__ == "main":
    __main__
else:
    generate_file()