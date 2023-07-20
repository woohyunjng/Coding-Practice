from collections import deque

N, M, V = map(int, input().split())
arr_p = [[] for i in range(N + 1)]

for i in range(M):
    A, B = map(int, input().split())
    arr_p[A].append(B)
    arr_p[B].append(A)

for i in range(1, N + 1):
    arr_p[i] = sorted(arr_p[i])

dfs_checked = [False for i in range(N + 1)]
bfs_checked = [False for i in range(N + 1)]


def dfs(P):
    dfs_checked[P] = True
    print(P, end=" ")

    for i in arr_p[P]:
        if not dfs_checked[i]:
            dfs(i)


def bfs(P):
    q = deque([P])
    bfs_checked[P] = True

    while len(q):
        for i in arr_p[q[-1]]:
            if not bfs_checked[i]:
                bfs_checked[i] = True
                q.appendleft(i)
        print(q.pop(), end=" ")


dfs(V)
print(end="\n")

bfs(V)
