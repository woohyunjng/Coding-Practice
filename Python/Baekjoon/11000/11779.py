from sys import stdin
from heapq import heappop, heappush

N = int(stdin.readline())
M = int(stdin.readline())
arr = [[] for i in range(N + 1)]

for i in range(M):
    A, B, C = map(int, stdin.readline().rstrip().split())
    arr[A].append((C, B))

A, B = map(int, stdin.readline().rstrip().split())

dp = [(1e9, []) for i in range(N + 1)]
dp[A] = (0, [A])

hq = []
heappush(hq, (0, A))

while len(hq):
    i, j = heappop(hq)
    if dp[j][0] < i:
        continue

    for x, y in arr[j]:
        if dp[y][0] > i + x:
            dp[y] = (i + x, dp[j][1] + [y])
            heappush(hq, (dp[y][0], y))

print(dp[B][0])
print(len(dp[B][1]))
print(*dp[B][1])
