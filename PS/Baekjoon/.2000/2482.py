from math import comb

N = int(input())
K = int(input())

if N >= K * 2:
    print((comb(N - K - 1, N - K * 2) + comb(N - K, N - K * 2)) % (10**9 + 3) if K >= 2 else N)
else:
    print(0)
