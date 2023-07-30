from math import comb

N, K = map(int, input().split())
print(comb(K + N - 1, N) % 1000000000)
