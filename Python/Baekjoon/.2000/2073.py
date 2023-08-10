D, P = map(int, input().split())
arr = [(0, 0)]

for i in range(P):
    arr.append(tuple(map(int, input().split())))

dp = [0 for j in range(D + 1)]
dp[0] = 1e9

for i in range(1, P + 1):
    new_dp = dp.copy()
    for j in range(D + 1):
        dp[j] = new_dp[j]
        if j >= arr[i][0]:
            dp[j] = max(dp[j], min(new_dp[j - arr[i][0]], arr[i][1]))

print(dp[D])
