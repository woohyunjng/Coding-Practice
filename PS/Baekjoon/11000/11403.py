from collections import deque

N = int(input())
arr = [[] for i in range(N)]

for i in range(N):
    ip_arr = list(map(int, input().split()))
    for j in range(N):
        if ip_arr[j]:
            arr[i].append(j)

for i in range(N):
    checked = [False for j in range(N)]
    checked[i] = True

    q = deque([i])
    go = [0 for j in range(N)]

    while len(q):
        p = q.pop()

        for j in arr[p]:
            if j == i:
                go[i] = 1
            if checked[j]:
                continue

            checked[j] = True
            q.append(j)
            go[j] = 1

    print(" ".join(map(str, go)))
