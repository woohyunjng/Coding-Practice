C, N = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

dp = [1e9 for j in range(C + 100)]
dp[0] = 0

for i in range(1, N + 1):
    for j in range(arr[i - 1][1], C + 100):
        dp[j] = min(dp[j], dp[j - arr[i - 1][1]] + arr[i - 1][0])

print(min(dp[C:]))
