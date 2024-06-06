N, M = map(int, input().split())
arr = []

for i in range(M):
    A, B, C = map(int, input().split())
    arr.append((A - 1, B - 1, C))

dp = [1e12 for i in range(N)]
dp[0] = 0
cycle = False

for i in range(N):
    for a, b, c in arr:
        if dp[a] != 1e12 and c + dp[a] < dp[b]:
            dp[b] = c + dp[a]
            if i == N - 1:
                cycle = True

if cycle:
    print(-1)
else:
    for i in range(1, N):
        print(dp[i] if dp[i] < 1e12 else -1)
