from collections import deque

N, M = map(int, input().split())
arr = [[] for i in range(N + 1)]

for i in range(M):
    U, V = map(int, input().split())
    arr[U].append(V)
    arr[V].append(U)

res = 0
checked = [False for i in range(N + 1)]
for i in range(1, N + 1):
    if checked[i]:
        continue

    res += 1
    q = deque([i])

    while len(q):
        p = q.pop()
        for j in arr[p]:
            if checked[j]:
                continue
            checked[j] = True
            q.append(j)

print(res)
