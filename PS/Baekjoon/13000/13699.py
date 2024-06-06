from math import comb

N = int(input())
print(comb(N * 2, N) // (N + 1))
