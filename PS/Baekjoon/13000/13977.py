from sys import stdin

MOD = 10**9 + 7


def pw(A, B):
    if B == 0:
        return 1

    if B % 2:
        return pw(A, B // 2) ** 2 * A % MOD
    else:
        return pw(A, B // 2) ** 2 % MOD


M = int(stdin.readline())
dp = [1, 1]

for i in range(M):
    N, K = map(int, stdin.readline().rstrip().split())

    if N >= len(dp):
        for j in range(len(dp), N + 1):
            dp.append(dp[-1] * j % MOD)

    print(dp[N] * pw(dp[N - K] * dp[K] % MOD, MOD - 2) % MOD)
