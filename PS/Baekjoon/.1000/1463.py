N = int(input())
dp = [0, 0]

for i in range(2, N + 1):
    ps = [dp[i - 1]]
    if not i % 2:
        ps.append(dp[i // 2])
    if not i % 3:
        ps.append(dp[i // 3])
    dp.append(min(ps) + 1)

print(dp[N])
