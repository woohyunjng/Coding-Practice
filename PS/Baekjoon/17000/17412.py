from sys import stdin
from collections import deque

N, P = map(int, stdin.readline().rstrip().split())
res = 0

arr = [[] for i in range(N + 1)]
flow = [[[0, 0] for j in range(N + 1)] for i in range(N + 1)]

for i in range(P):
    A, B = map(int, stdin.readline().rstrip().split())
    arr[A].append(B)
    arr[B].append(A)
    flow[A][B][1] = 1

while True:
    parent = [-1 for i in range(N + 1)]
    st = deque([1])
    parent[1] = 0

    while len(st):
        A = st.pop()
        if A == 2:
            break

        for i in arr[A]:
            if flow[A][i][0] >= flow[A][i][1] or parent[i] != -1:
                continue
            parent[i] = A
            st.append(i)
    else:
        break

    A = 2
    while parent[A] != 0:
        flow[parent[A]][A][0] += 1
        flow[A][parent[A]][0] -= 1
        A = parent[A]
    res += 1

print(res)
