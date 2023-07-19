from collections import deque
from sys import stdin

N = int(stdin.readline())
d = deque([])

for i in range(N):
    S = stdin.readline().rstrip()
    if S.startswith("push_front"):
        d.appendleft(int(S[11:]))
    elif S.startswith("push_back"):
        d.append(int(S[10:]))
    elif S == "pop_front":
        if not len(d):
            print(-1)
            continue
        print(d.popleft())
    elif S == "pop_back":
        if not len(d):
            print(-1)
            continue
        print(d.pop())
    elif S == "size":
        print(len(d))
    elif S == "empty":
        print(0 if len(d) else 1)
    elif S == "front":
        if not len(d):
            print(-1)
            continue
        print(d[0])
    elif S == "back":
        if not len(d):
            print(-1)
            continue
        print(d[-1])    
