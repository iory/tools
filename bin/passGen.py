#!/usr/bin/env python
# -*- coding:utf-8 -*-

# generate password on terminal

import sys
import random
import math

def main():
    if len(sys.argv) < 3:
        print("Usage: {} <length> <count>".format(sys.argv[0]))
        sys.exit()
    passlen = int(sys.argv[1])
    count = int(sys.argv[2])
    s = 'abcdefghijkmnopqrstuvwxyzABCDEFGHIJKLMNPQRSTUVWXYZ123456789'
    for i in range(count):
        password = ''
        for j in range(passlen):
            password += random.choice(s)
        print(password)

if __name__=="__main__":
    main()
