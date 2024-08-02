from math import comb

N, K = map(int, input().split())
K -= 1

MOD = 10**9
res = comb(N - 3, K) % MOD * comb(N + K - 1, K) // (K + 1) % MOD
print(res)
