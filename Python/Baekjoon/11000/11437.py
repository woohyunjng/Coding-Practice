from collections import deque

N = int(input())
arr = [[] for i in range(N + 1)]

for i in range(N - 1):
    A, B = map(int, input().split())
    arr[A].append(B)
    arr[B].append(A)

st = deque([1])
checked = [False for i in range(N + 1)]
checked[1] = True

depth = [0 for i in range(N + 1)]
parent = [0 for i in range(N + 1)]

while len(st):
    p = st.pop()
    for q in arr[p]:
        if checked[q]:
            continue

        checked[q] = True
        parent[q] = p
        depth[q] = depth[p] + 1
        st.append(q)

M = int(input())
for i in range(M):
    A, B = map(int, input().split())
    if depth[B] > depth[A]:
        A, B = B, A

    for j in range(depth[A] - depth[B]):
        A = parent[A]

    while A != B:
        A, B = parent[A], parent[B]

    print(A)
