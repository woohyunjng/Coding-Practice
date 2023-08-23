N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

dp = [[[0 for k in range(3)] for j in range(N)] for i in range(N)]
dp[0][1] = [1, 0, 0]

for i in range(N):
    for j in range(N):
        if arr[i][j] != 0:
            continue

        if i != 0:
            dp[i][j][1] += dp[i - 1][j][1]
            dp[i][j][1] += dp[i - 1][j][2]
        if j != 0:
            dp[i][j][0] += dp[i][j - 1][0]
            dp[i][j][0] += dp[i][j - 1][2]
        if i != 0 and j != 0:
            if arr[i - 1][j] == 0 and arr[i][j - 1] == 0:
                dp[i][j][2] += sum(dp[i - 1][j - 1])

print(sum(dp[N - 1][N - 1]))
