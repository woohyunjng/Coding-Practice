from collections import deque

N, M = map(int, input().split())
arr = [[] for i in range(N + 1)]

boss = list(map(int, input().split()))
for i in range(1, N + 1):
    arr[boss[i - 1] if boss[i - 1] > 0 else 0].append(i)

dp = [0 for i in range(N + 1)]
for i in range(M):
    j, w = map(int, input().split())
    dp[j] += w

q = deque([0])
while q:
    p = q.popleft()
    for i in arr[p]:
        dp[i] += dp[p]
        q.append(i)

print(" ".join(map(str, dp[1:])))
