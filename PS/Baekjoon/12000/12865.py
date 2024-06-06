N, K = map(int, input().split())

arr = [[100000000000000000000000000000000, 1]]
dp = [[0 for j in range(K + 1)] for i in range(N + 1)]

for i in range(N):
    W, V = map(int, input().split())
    arr.append([W, V])

for i in range(N + 1):
    for j in range(1, K + 1):
        if arr[i][0] <= j:
            dp[i][j] = dp[i - 1][j - arr[i][0]] + arr[i][1]
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i][j])

print(dp[N][K])
