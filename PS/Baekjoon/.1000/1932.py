N = int(input())
arr, dp = [], []

for i in range(N):
    arr.append(list(map(int, input().split())))

dp.append([arr[0][0]])

for i in range(1, N):
    dp.append([])
    for j in range(i + 1):
        if j == 0:
            dp[-1].append(dp[i - 1][0] + arr[i][0])
        elif j == i:
            dp[-1].append(dp[i - 1][i - 1] + arr[i][i])
        else:
            dp[-1].append(max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j])

print(max(dp[N - 1]))
