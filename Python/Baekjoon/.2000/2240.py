T, W = map(int, input().split())
dp = [[[0, 0] for j in range(W + 1)] for i in range(T)]
arr = []

for i in range(T):
    A = int(input()) - 1

    if i == 0:
        dp[i][W][0] = int(A == 0)
        dp[i][W - 1][1] = int(A == 1)
    else:
        for j in range(W, 0, -1):
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + int(A == 0))
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + int(A == 1))
            dp[i][j - 1][0] = dp[i - 1][j][1] + int(A == 0)
            dp[i][j - 1][1] = dp[i - 1][j][0] + int(A == 1)

        dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][0] + int(A == 0))
        dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][1] + int(A == 1))

print(max([max(dp[T - 1][i]) for i in range(W + 1)]))
