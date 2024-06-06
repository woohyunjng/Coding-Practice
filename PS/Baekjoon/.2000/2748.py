N = int(input())
dp = [0, 1]

if N >= len(dp):
    while N >= len(dp):
        dp.append(dp[-1] + dp[-2])
print(dp[N])
