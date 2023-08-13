# 7 / 100

from sys import stdin
from collections import deque

N, Q = map(int, stdin.readline().rstrip().split())
P = list(map(lambda x: int(x) - 1, stdin.readline().rstrip().split()))
A = list(map(int, stdin.readline().rstrip().split()))

q = deque([])
arr = [0 for i in range(N)]
for i in P:
    arr[i] += 1

for i in range(N):
    if not arr[i]:
        q.append(i)

res = []

while len(q):
    p = q.popleft()
    res.append(p)

    arr[P[p - 1]] -= 1
    if not arr[P[p - 1]] and P[p - 1] != 0:
        q.append(P[p - 1])
res.append(0)
res = list(reversed(res))

for i in range(Q + 1):
    if i:
        X, Y = map(int, stdin.readline().rstrip().split())
        A[X - 1] = Y

    new_A = A.copy()
    val = 0
    while True:
        empt = 0
        for j in res:
            if not new_A[j]:
                empt += 1
                continue

            if not j:
                new_A[j] -= 1
            else:
                new_A[j] -= 1
                new_A[P[j - 1]] += 1

        if empt == N:
            break
        val += 1

    print(val)
