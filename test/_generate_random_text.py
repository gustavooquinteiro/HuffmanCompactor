# -*- coding: utf-8 -*-

import random


def generate_rand_text(tamanho):
    caracters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n "
    text = ""
    while(len(text) != tamanho):
        text += random.choice(caracters)
    return text


def generate_file(upper_bound):
    for i in range(1, upper_bound):
        nome = 'example_' + str(i) + '.in'
        size = random.randint(1000, 1073741824)
        with open(nome, 'w') as arquivo:
            arquivo.write(generate_rand_text(size))


upper_bound = int(input("Type a upper bound for archive quantity: "))
generate_file(upper_bound)