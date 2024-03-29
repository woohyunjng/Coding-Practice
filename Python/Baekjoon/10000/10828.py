from collections import deque
from sys import stdin

N = int(stdin.readline())
d = deque([])

for i in range(N):
    S = stdin.readline().rstrip()
    if S.startswith("push"):
        d.append(int(S[5:]))
    elif S == "pop":
        if not len(d):
            print(-1)
            continue
        print(d.pop())
    elif S == "size":
        print(len(d))
    elif S == "empty":
        print(0 if len(d) else 1)
    elif S == "top":
        if not len(d):
            print(-1)
            continue
        print(d[-1])
