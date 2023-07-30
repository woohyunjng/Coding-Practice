N, K = map(int, input().split())
arr = []

for i in range(N):
    arr.append(int(input()))

dp = [0 for i in range(K + 1)]
dp[0] = 1

for i in arr:
    for j in range(i, K + 1):
        dp[j] += dp[j - i]

print(dp[K])
