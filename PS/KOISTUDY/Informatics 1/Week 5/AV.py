dp = [0, 1, 1]
N = int(input()) + 2
for i in range(3, N + 1):
    dp.append(dp[i - 1] + dp[i - 2])

print(dp[N], dp[N - 1])
