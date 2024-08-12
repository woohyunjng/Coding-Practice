from sys import stdin
from collections import deque

input = stdin.readline

N = int(input())
M = int(input())

arr = [[] for i in range(N + 1)]
visited = [False] * (N + 1)

for i in range(M):
    A, B = map(int, input().split())
    arr[A].append(B)
    arr[B].append(A)

q = deque([])
q.append((1, 0))
visited[1] = True

res = 0

while q:
    node, cnt = q.popleft()
    if cnt > 2:
        break

    res += 1
    for i in arr[node]:
        if not visited[i]:
            visited[i] = True
            q.append((i, cnt + 1))

print(res - 1)
