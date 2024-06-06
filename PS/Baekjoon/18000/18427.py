N, M, H = map(int, input().split())
arr = [[]]

for i in range(N):
    arr.append(list(map(int, input().split())))

dp = [[0 for j in range(H + 1)] for i in range(N + 1)]
for i in range(1, N + 1):
    for j in arr[i]:
        for k in range(H + 1):
            dp[i][k] = dp[i - 1][k] if not dp[i][k] else dp[i][k]
            if k == j:
                dp[i][k] += 1
            elif k > j:
                dp[i][k] += dp[i - 1][k - j]

print(dp[N][H] % 10007)
