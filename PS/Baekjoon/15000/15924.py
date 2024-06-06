N, M = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(input()))

dp = [[0 for j in range(M)] for i in range(N)]
dp[N - 1][M - 1] = 1

for i in range(N - 1, -1, -1):
    for j in range(M - 1, -1, -1):
        if i < N - 1 and arr[i][j] != "E":
            dp[i][j] = (dp[i][j] + dp[i + 1][j]) % 1000000009
        if j < M - 1 and arr[i][j] != "S":
            dp[i][j] = (dp[i][j] + dp[i][j + 1]) % 1000000009

res = 0
for i in dp:
    res = (res + sum(i)) % 1000000009

print(res % 1000000009)
