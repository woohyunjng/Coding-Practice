from collections import deque

N, M = map(int, input().split())
arr = [[] for i in range(N + 1)]

for i in range(M):
    A, B = map(int, input().split())
    arr[A].append(B)
    arr[B].append(A)

mn, res = 100000000000000000000, -1
for i in range(1, N + 1):
    checked = [False for i in range(N + 1)]
    q = deque([i])
    checked[i] = True

    friend = [0 for i in range(N + 1)]

    while len(q):
        j = q.popleft()
        for k in arr[j]:
            if not checked[k]:
                checked[k] = True
                q.append(k)
                friend[k] = friend[j] + 1

    sm = sum(friend)
    if sm < mn:
        mn = sm
        res = i
    elif sm == mn:
        res = min(res, i)

print(res)
