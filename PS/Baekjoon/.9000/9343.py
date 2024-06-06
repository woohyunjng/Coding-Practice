from sys import stdin

MOD = 10**9 + 7


def pw(A, B):
    if B == 0:
        return 1

    if B % 2:
        return pw(A, B // 2) ** 2 * A % MOD
    else:
        return pw(A, B // 2) ** 2 % MOD


T = int(stdin.readline())
dp = [1, 1]

for i in range(T):
    N = int(stdin.readline())

    if N * 2 >= len(dp):
        for j in range(len(dp), N * 2 + 1):
            dp.append(dp[-1] * j % MOD)

    print(dp[N * 2] * pw(dp[N] ** 2 * (N + 1) % MOD, MOD - 2) % MOD)
