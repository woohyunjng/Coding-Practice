from sys import stdin
from math import gcd

MOD = 10**9 + 7


def pow(N, K):
    if K == 0:
        return 1
    elif not K % 2:
        return pow(N, K // 2) ** 2 % MOD
    else:
        return pow(N, K - 1) * N % MOD


M = int(stdin.readline())
res = 0

for i in range(M):
    N, S = map(int, stdin.readline().rstrip().split())
    G = gcd(N, S)
    res += (S // G) * pow(N // G, MOD - 2) % MOD

print(res % MOD)
