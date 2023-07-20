n = int(input())
dp = [0, 1, 3]

for i in range(3, n + 1):
    dp.append(dp[-1] + dp[-2] * 2)

print(dp[n] % 10007)
