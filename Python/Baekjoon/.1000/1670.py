from math import comb

N = int(input()) // 2
print(comb(N * 2, N) // (N + 1) % 987654321)
