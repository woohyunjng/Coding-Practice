T = int(input())
dp = [(1, 0), (0, 1)]

for _ in range(T):
    N = int(input())
    for i in range(len(dp), N + 1):
        dp.append((dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1]))
    print(*dp[N])
