from heapq import heappop, heappush

N, M = map(int, input().split())
arr = [[] for i in range(N + 1)]

for i in range(M):
    A, B, C = map(int, input().split())
    arr[A].append((C, B))
    arr[B].append((C, A))

q = []
heappush(q, (0, 1))

dp = [1e9 for i in range(N + 1)]
dp[1] = 0

while len(q):
    i, j = heappop(q)
    for x, y in arr[j]:
        if dp[y] > i + x:
            dp[y] = i + x
            heappush(q, (dp[y], y))

print(dp[N])
