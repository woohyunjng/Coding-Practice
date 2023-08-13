from sys import stdin

N = int(stdin.readline().rstrip())
arr = list(map(int, stdin.readline().rstrip().split()))

dp = [[0 for j in range(N)] for i in range(N)]
for i in range(N - 1, -1, -1):
    for j in range(i, N):
        if i == j:
            dp[i][j] = 1
            continue
        elif j - i == 1 and arr[j] == arr[i]:
            dp[i][j] = 1
            continue

        if arr[j] == arr[i] and dp[i + 1][j - 1]:
            dp[i][j] = 1

M = int(stdin.readline().rstrip())
for i in range(M):
    S, E = map(int, stdin.readline().rstrip().split())
    print(dp[S - 1][E - 1])
