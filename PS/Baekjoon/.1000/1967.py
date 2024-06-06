from collections import deque

N = int(input())
arr = [[] for i in range(N + 1)]

for i in range(N - 1):
    A, B, C = map(int, input().split())
    arr[A].append((C, B))
    arr[B].append((C, A))

dp = [[1, 0] for i in range(N + 1)]
checked = [False for i in range(N + 1)]
checked[1] = True
q = deque([1])

while len(q):
    p = q.popleft()
    for i, j in arr[p]:
        if checked[j]:
            continue

        checked[j] = True
        dp[j] = [dp[p][0] + i, j]
        q.append(j)

A = max(dp, key=lambda x: x[0])[1]
dp = [0 for i in range(N + 1)]
checked = [False for i in range(N + 1)]
checked[A] = True
q = deque([A])

while len(q):
    p = q.pop()
    for i, j in arr[p]:
        if checked[j]:
            continue
        checked[j] = True
        dp[j] = dp[p] + i
        q.append(j)

print(max(dp))
