N, M = map(int, input().split())
A = list(map(int, input().split()))
c = list(map(int, input().split()))
sum_c = sum(c)

dp = [[0 for j in range(sum_c + 1)] for i in range(N + 1)]

for i in range(1, N + 1):
    for j in range(sum_c + 1):
        if j >= c[i - 1]:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i - 1]] + A[i - 1])
        else:
            dp[i][j] = dp[i - 1][j]

mn = 1e9
for i in range(sum_c + 1):
    if dp[N][i] != 1e9 and dp[N][i] >= M:
        mn = i
        break

print(mn)
