#! /usr/bin/env python

from random import randint
from sys import argv

# items, item height, total height
Nmin, Nmax, Amax, Hmin, Hmax = [int(i) for i in argv[1:]]

N = randint(Nmin, Nmax)
print N
print ' '.join( [str(randint(1,Amax)) for i in range(0,N)] )
print randint(Hmin, Hmax)
