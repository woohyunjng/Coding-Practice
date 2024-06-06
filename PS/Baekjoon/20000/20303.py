from sys import stdin
from collections import deque

N, M, K = map(int, stdin.readline().rstrip().split())
c = list(map(int, stdin.readline().rstrip().split()))
arr = [[] for i in range(N)]

for i in range(M):
    a, b = map(int, stdin.readline().rstrip().split())
    arr[a - 1].append(b - 1)
    arr[b - 1].append(a - 1)

res = []
checked = [False for i in range(N)]

for i in range(N):
    if checked[i]:
        continue
    checked[i] = True

    q = deque([i])
    candy, child = 0, 0

    while len(q):
        p = q.popleft()
        candy += c[p]
        child += 1

        for j in arr[p]:
            if not checked[j]:
                q.append(j)
                checked[j] = True

    res.append((candy, child))

dp = [[0 for i in range(K)]]
for i, j in res:
    dp.append([])
    for k in range(K):
        if k < j:
            dp[-1].append(dp[-2][k])
        else:
            dp[-1].append(max(dp[-2][k], dp[-2][k - j] + i))

print(dp[len(res)][K - 1])
