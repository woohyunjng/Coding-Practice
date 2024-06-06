from math import comb

k, n = map(int, input().split())
print(comb(n + k, k + 1) % 1000000007)
