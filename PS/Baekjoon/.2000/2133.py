N = int(input())
dp = [1, 0, 3]

for i in range(3, N + 1):
    if i % 2:
        dp.append(0)
        continue

    dp.append(4 * dp[i - 2] - dp[i - 4])

print(dp[N])
