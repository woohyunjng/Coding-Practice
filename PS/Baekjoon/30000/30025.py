N, M, K = map(int, input().split())
arr = list(map(int, input().split()))

MOD = 10**9 + 7

dp = [[[0, 0] for j in range(K)] for i in range(M)]
for i in arr:
    if i:
        dp[0][i % K][0] += 1
        dp[0][i % K][1] += 1
    elif i == 0:
        dp[0][i % K][1] += 1

for i in range(1, M):
    for j in arr:
        x = j * 10**i % K
        for k in range(K):
            if j != 0:
                dp[i][(k + x) % K][0] = (dp[i][(k + x) % K][0] + dp[i - 1][k][1]) % MOD
                dp[i][(k + x) % K][1] = (dp[i][(k + x) % K][1] + dp[i - 1][k][1]) % MOD
            else:
                dp[i][(k + x) % K][1] = (dp[i][(k + x) % K][1] + dp[i - 1][k][1]) % MOD

print(dp[M - 1][0][0] % MOD)
