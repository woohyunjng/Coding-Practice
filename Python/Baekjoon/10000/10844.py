N = int(input())
dp = [[], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]]

for i in range(2, N + 1):
    dp.append([])
    for j in range(0, 10):
        if j == 0:
            dp[i].append(dp[i - 1][j + 1])
        elif j == 9:
            dp[i].append(dp[i - 1][j - 1])
        else:
            dp[i].append(dp[i - 1][j - 1] + dp[i - 1][j + 1])

print(sum(dp[N]) % 1000000000)
