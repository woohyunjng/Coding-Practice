n = int(input())
dp = [0, 1]

if n >= len(dp):
    while n >= len(dp):
        dp.append(dp[-1] + dp[-2])

print(dp[n], n - 2)
