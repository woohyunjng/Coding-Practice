from collections import deque
from sys import stdin

N = int(stdin.readline())
dq = deque([])

for i in range(N):
    x, r = map(int, stdin.readline().rstrip().split())
    while len(dq):
        r = min(r, (x - dq[-1][0]) ** 2 / (4 * dq[-1][1]))
        if r > dq[-1][1]:
            dq.pop()
        else:
            break

    print(r)
    dq.append((x, r))
