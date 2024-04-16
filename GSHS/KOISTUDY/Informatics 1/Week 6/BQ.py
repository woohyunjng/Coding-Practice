N = int(input())
arr = [[0 for j in range(N)] for i in range(N)]
dp = [[0 for j in range(N)] for i in range(N)]

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(i + 1):
        arr[i][j] = line[j]

dp[0][0] = arr[0][0]
for i in range(1, N):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = dp[i - 1][j] + arr[i][j]
        elif j == i:
            dp[i][j] = dp[i - 1][j - 1] + arr[i][j]
        else:
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]

print(max(dp[N - 1]))
