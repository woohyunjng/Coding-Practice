from collections import deque

N = int(input())
arr = [[] for i in range(N + 1)]
parent = [0 for i in range(N + 1)]

for i in range(N - 1):
    x, y = map(int, input().split())
    arr[x].append(y)
    arr[y].append(x)

checked = [False for i in range(N + 1)]
q = deque([1])
while len(q):
    p = q.pop()
    for i in arr[p]:
        if checked[i]:
            continue
        checked[i] = True
        parent[i] = p
        q.append(i)

for i in range(2, N + 1):
    print(parent[i])
