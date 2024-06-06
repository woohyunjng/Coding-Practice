N, Q = map(int, input().split())
arr = [0 for i in range(N)]
dp = [0 for i in range(N)]

for i in range(Q):
    A, B, W = map(int, input().split())
    dp[A - 1] += W
    if B < N:
        dp[B] += -W

arr[0] = dp[0]
for i in range(1, N):
    arr[i] = dp[i] + arr[i - 1]

print(*arr)
