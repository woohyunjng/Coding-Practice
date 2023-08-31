from sys import stdin
from collections import deque

N, L = map(int, stdin.readline().rstrip().split())
arr = list(map(int, stdin.readline().rstrip().split()))
dq = deque([])

for i in range(N):
    if not len(dq) or arr[i] < dq[0][0]:
        dq.appendleft((arr[i], i))
    else:
        while dq[-1][0] > arr[i]:
            dq.pop()
        dq.append((arr[i], i))

    while dq[0][1] < i - L + 1:
        dq.popleft()

    print(dq[0][0], end=" ")
