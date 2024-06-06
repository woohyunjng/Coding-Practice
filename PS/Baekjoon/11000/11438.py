from sys import stdin
from collections import deque

N = int(stdin.readline())
arr = [[] for i in range(N + 1)]

for i in range(N - 1):
    A, B = map(int, stdin.readline().rstrip().split())
    arr[A].append(B)
    arr[B].append(A)

st = deque([1])
checked = [False for i in range(N + 1)]
checked[1] = True

depth = [0 for i in range(N + 1)]
parent = [[0 for j in range(18)] for i in range(N + 1)]

while len(st):
    p = st.pop()
    for q in arr[p]:
        if checked[q]:
            continue

        checked[q] = True
        parent[q][0] = p
        depth[q] = depth[p] + 1

        k = 1
        while 2**k <= N:
            if not parent[q][k - 1]:
                break
            parent[q][k] = parent[parent[q][k - 1]][k - 1]
            k += 1

        st.append(q)

top = [1]
for i in range(17):
    top.append(top[-1] * 2)

M = int(stdin.readline())
for i in range(M):
    A, B = map(int, stdin.readline().rstrip().split())
    if depth[B] > depth[A]:
        A, B = B, A

    diff = depth[A] - depth[B]
    for j in range(17, -1, -1):
        if top[j] <= diff:
            diff -= top[j]
            A = parent[A][j]

    for j in range(17, -1, -1):
        if parent[A][j] != parent[B][j]:
            A, B = parent[A][j], parent[B][j]
    if A != B:
        A = parent[A][0]

    print(A)
