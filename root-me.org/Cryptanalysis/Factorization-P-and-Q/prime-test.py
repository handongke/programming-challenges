#!/usr/bin/python

import gmpy2


with open('n.txt', 'r') as f:
 lines = f.readlines() # read all lines from file

n_str =lines[0]
print 'hex', n_str

n = int(n_str, 16)
print 'n =', n

np = gmpy2.is_prime(n)
print 'is prime =', np
