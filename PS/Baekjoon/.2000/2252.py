from collections import deque

N, M = map(int, input().split())
arr = [[] for i in range(N + 1)]
in_degree = [0 for i in range(N + 1)]

for i in range(M):
    A, B = map(int, input().split())
    arr[A].append(B)
    in_degree[B] += 1

q = deque([])
for i in range(1, N + 1):
    if not in_degree[i]:
        q.append(i)

res = []
while len(q):
    p = q.popleft()
    res.append(p)
    for i in arr[p]:
        in_degree[i] -= 1
        if not in_degree[i]:
            q.append(i)

print(" ".join(map(str, res)))
