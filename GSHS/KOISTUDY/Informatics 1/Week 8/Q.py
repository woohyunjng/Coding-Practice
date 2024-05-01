N, M = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(map(int, input().strip())))

dp = [[0 for j in range(M)] for i in range(N)]
for i in range(M):
    dp[0][i] = arr[0][i]

for i in range(1, N):
    for j in range(M):
        if arr[i][j]:
            dp[i][j] = dp[i - 1][j] + 1

print("\n".join(map(lambda x: " ".join(map(str, x)), dp)))
