from sys import stdin
from fractions import Fraction

input = stdin.readline
T = int(input())

MOD = 998244353

for t in range(T):
    N = int(input())
    A = list(input())
    B = list(input())

    cnt = 0
    for i in range(N):
        if A[i] != B[i]:
            cnt += 1

    bef = [0] * (N + 1)
    bef[N] = 1 * pow(1, -1, MOD) % MOD

    for i in range(N - 1, 0, -1):
        bef[i] = (
            N
            * pow(i, -1, MOD)
            * ((N - i) * pow(N, -1, MOD) * bef[i + 1] % MOD + 1)
            % MOD
        )

    res = 0
    for i in range(1, cnt + 1):
        res = (res + bef[i]) % MOD

    print(res)
