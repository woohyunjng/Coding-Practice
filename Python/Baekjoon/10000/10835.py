from sys import stdin

N = int(stdin.readline())
A = list(map(int, stdin.readline().rstrip().split()))
B = list(map(int, stdin.readline().rstrip().split()))

dp = [[0 for j in range(N + 1)] for i in range(N + 1)]

for i in range(N - 1, -1, -1):
    for j in range(N - 1, -1, -1):
        if B[j] < A[i]:
            dp[i][j] = dp[i][j + 1] + B[j]
        dp[i][j] = max(dp[i][j], dp[i + 1][j], dp[i + 1][j + 1])

print(dp[0][0])
