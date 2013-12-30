#! /usr/bin/env python

from random import randint
from sys import argv

# items, item height, total height
Nmin, Nmax, Mmin, Mmax, ABmin, ABmax, CDmin, CDmax = [int(i) for i in argv[1:]]

N = randint(Nmin, Nmax)
M = randint(Mmin, Mmax)
print N, M
for i in range(0,N):
    print randint(ABmin, ABmax), randint(ABmin, ABmax)
for i in range(0,M):
    print randint(1,N), randint(1,N), randint(CDmin, CDmax), randint(CDmin, CDmax)
