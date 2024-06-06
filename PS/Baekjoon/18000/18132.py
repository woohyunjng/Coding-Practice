from sys import stdin
from math import comb

T = int(stdin.readline())

for i in range(T):
    E = int(stdin.readline()) + 1
    print(comb(E * 2, E) // (E + 1) % (10**9 + 7))
