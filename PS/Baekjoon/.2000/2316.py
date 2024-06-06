from sys import stdin
from collections import deque

N, P = map(int, stdin.readline().rstrip().split())
res = 0

arr = [[] for i in range(N * 2 + 2)]
flow = [[[0, 0] for j in range(N * 2 + 2)] for i in range(N * 2 + 2)]

for i in range(3, N + 1):
    arr[i * 2].append(i * 2 + 1)
    arr[i * 2 + 1].append(i * 2)
    flow[i * 2][i * 2 + 1][1] = 1

for i in range(P):
    A, B = map(int, stdin.readline().rstrip().split())
    A, B = min(A, B), max(A, B)
    if A == 1:
        arr[3].append(B * 2)
        arr[B * 2].append(3)
        flow[3][B * 2][1] = 1
    elif A == 2:
        arr[4].append(B * 2 + 1)
        arr[B * 2 + 1].append(4)
        flow[B * 2 + 1][4][1] = 1
    else:
        arr[A * 2 + 1].append(B * 2)
        arr[B * 2].append(A * 2 + 1)
        flow[A * 2 + 1][B * 2][1] = 1
        arr[A * 2].append(B * 2 + 1)
        arr[B * 2 + 1].append(A * 2)
        flow[B * 2 + 1][A * 2][1] = 1

while True:
    parent = [-1 for i in range(N * 2 + 2)]
    st = deque([3])
    parent[3] = 0

    while len(st):
        A = st.pop()
        if A == 4:
            break

        for i in arr[A]:
            if flow[A][i][0] >= flow[A][i][1] or parent[i] != -1:
                continue
            parent[i] = A
            st.append(i)
    else:
        break

    A = 4
    while parent[A] != 0:
        flow[parent[A]][A][0] += 1
        flow[A][parent[A]][0] -= 1
        A = parent[A]
    res += 1

print(res)
