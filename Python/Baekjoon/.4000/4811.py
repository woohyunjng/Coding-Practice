from sys import stdin
from math import comb

while True:
    N = int(stdin.readline())
    if not N:
        break

    print(comb(2 * N, N) // (N + 1))
