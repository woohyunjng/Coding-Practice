from collections import defaultdict

MOD = 10**9 + 7
dp = defaultdict(int)
dp[0] = 0
dp[1] = 1
dp[2] = 1


def get_fibo(N):
    if dp[N] or not N:
        return dp[N]
    elif dp[N - 1] and dp[N - 2]:
        dp[N] = dp[N - 1] + dp[N - 2]
        return dp[N - 1] + dp[N - 2]
    elif not N % 2:
        dp[N // 2 + 1] = get_fibo(N // 2 + 1) % MOD
        dp[N // 2 - 1] = get_fibo(N // 2 - 1) % MOD
        return dp[N // 2 + 1] ** 2 - dp[N // 2 - 1] ** 2
    else:
        dp[N // 2 + 1] = get_fibo(N // 2 + 1) % MOD
        dp[N // 2] = get_fibo(N // 2) % MOD
        return dp[N // 2 + 1] ** 2 + dp[N // 2] ** 2


N = int(input())
print(get_fibo(N) % MOD)
