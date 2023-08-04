N = int(input())
M = int(input())

dp = [[1e9 for j in range(N)] for i in range(N)]

for i in range(M):
    a, b, c = map(int, input().split())
    dp[a - 1][b - 1] = min(dp[a - 1][b - 1], c)

for i in range(N):
    dp[i][i] = 0

for i in range(N):
    for j in range(N):
        for k in range(N):
            dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k])

for i in range(N):
    for j in range(N):
        print(dp[i][j] if dp[i][j] < 1e9 else 0, end=" ")
    print()
