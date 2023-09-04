from sys import stdin

N, M, R = map(int, stdin.readline().rstrip().split())
T = list(map(int, stdin.readline().rstrip().split()))

dp = [[1e9 for j in range(N + 1)] for i in range(N + 1)]

for i in range(R):
    A, B, L = map(int, stdin.readline().rstrip().split())
    dp[A][B] = L
    dp[B][A] = L

for i in range(1, N + 1):
    dp[i][i] = 0

for i in range(1, N + 1):
    for j in range(1, N + 1):
        for k in range(1, N + 1):
            dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k])

mx = -1

for i in range(1, N + 1):
    res = 0

    for j in range(1, N + 1):
        if dp[i][j] <= M:
            res += T[j - 1]

    mx = max(mx, res)

print(mx)
