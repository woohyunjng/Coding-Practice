from sys import stdin
from collections import deque

input = stdin.readline
T = int(input())

for t in range(T):
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))
    res = 0

    arr = list(sorted(arr))
    dq = deque([])
    sm = 0

    for i in arr:
        sm += i
        dq.append(i)
        while len(dq) and (dq[0] < i - 1 or sm > M):
            sm -= dq[0]
            dq.popleft()
        res = max(res, sm)
    print(res)
