from sys import stdin
from math import ceil

N, M, K = map(int, stdin.readline().rstrip().split())
D, boss = [], []
res = 0

for i in range(N):
    D.append(int(stdin.readline()))
D = list(sorted(D, reverse=True))[:M]

for i in range(K):
    P, Q = map(int, stdin.readline().rstrip().split())
    boss.append((P, Q))

for i in D:
    dp = [[0 for j in range(901)] for i in range(K + 1)]
    for j in range(1, K + 1):
        for k in range(1, 901):
            if ceil(boss[j - 1][0] / i) <= k:
                dp[j][k] = dp[j - 1][k - ceil(boss[j - 1][0] / i)] + boss[j - 1][1]
            dp[j][k] = max(dp[j][k], dp[j][k - 1], dp[j - 1][k])

    res += dp[K][900]

print(res)
