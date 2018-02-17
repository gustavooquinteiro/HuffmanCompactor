# -*- coding: utf-8 -*-

import random
import os

ok = '[' + '\033[32m' + ' OK ' + '\033[0;0m' + ']'


def bytesto(bytes, to, bsize=1024):
    a = {'k': 1, 'm': 2, 'g': 3, 't': 4, 'p': 5, 'e': 6}
    r = float(bytes)
    for i in range(a[to]):
        r /= bsize
    return r


def generate_rand_text(size):
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n "
    text = ""
    while(len(text) != size):
        text += random.choice(characters)
    return text


def generate_file(upper_bound):
    print("	Generating test files... ")
    for i in range(upper_bound):
        filename = 'example_' + str(i + 1) + '.in'
        size = random.randint(1073700, 1073741844)
        # Size between 1 GB and 2 GB uncomment line below and comment line above
        # size = random.randint(1073741844,2059947370)
        print(('        Creating ' + filename))
        with open(filename, 'w') as archive:
            archive.write(generate_rand_text(size))
        createdFilename = '  Created ' + filename
        fileBytes = os.path.getsize(filename)
        fileSize = ' with %.1f' % bytesto(fileBytes, 'g') + ' GB'
        print((ok + createdFilename + fileSize))


def main():
    answer = "        Enter the number of test files that will be created: "
    quantity = int(input(answer))
    generate_file(quantity)
    print(ok + '  Generated test files')


if __name__ == '__main__':
    main()
