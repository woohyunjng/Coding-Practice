from sys import stdin
from collections import deque

N, R = map(int, stdin.readline().rstrip().split())
pr = [i for i in range(N + 1)]
rt, df = 0, 0


def find(i):
    if pr[i] != i:
        pr[i] = find(pr[i])
    return pr[i]


def uni(i, j):
    i, j = find(i), find(j)
    pr[max(i, j)] = min(i, j)


money = [[0 for j in range(N + 1)] for i in range(N + 1)]
arr = []
pw = []

for i in range(18):
    pw.append(1 << i)

for i in range(R):
    A, B, C = map(int, stdin.readline().rstrip().split())
    money[A][B] = C
    arr.append([C, A, B])

arr = list(sorted(arr))
child = [[] for i in range(N + 1)]
for C, A, B in arr:
    if find(A) == find(B):
        continue

    uni(find(A), find(B))
    df += C
    child[A].append([B, C])
    child[B].append([A, C])

    if not rt:
        rt = A

st = deque([rt])
checked = [False for i in range(N + 1)]
checked[rt] = True

depth = [0 for i in range(N + 1)]
parent = [[[0, 0] for j in range(18)] for i in range(N + 1)]

while len(st):
    p = st.pop()
    for A, B in child[p]:
        if checked[A]:
            continue

        checked[A] = True
        parent[A][0] = [p, B]
        depth[A] = depth[p] + 1

        K = 1
        while 1 << K <= N:
            if not parent[A][K - 1][0]:
                break
            parent[A][K] = [
                parent[parent[A][K - 1][0]][K - 1][0],
                max(parent[parent[A][K - 1][0]][K - 1][1], parent[A][K - 1][1]),
            ]
            K += 1

        st.append(A)


Q = int(stdin.readline())
for i in range(Q):
    A, B = map(int, stdin.readline().rstrip().split())
    base, res = money[A][B] + df, 0

    if depth[B] > depth[A]:
        A, B = B, A

    diff = depth[A] - depth[B]
    for j in range(17, -1, -1):
        if pw[j] <= diff:
            diff -= pw[j]
            res = max(res, parent[A][j][1])
            A = parent[A][j][0]

    for j in range(17, -1, -1):
        if parent[A][j][0] != parent[B][j][0]:
            res = max(res, parent[A][j][1], parent[B][j][1])
            A, B = parent[A][j][0], parent[B][j][0]

    if A != B:
        res = max(res, parent[A][0][1], parent[B][0][1])
    print(base - res)
