from collections import deque
from sys import stdin

N = int(stdin.readline())
dq = deque([])

for i in range(N):
    S = stdin.readline().rstrip()
    if S.startswith("1"):
        dq.appendleft(int(S[2:]))
    elif S.startswith("2"):
        dq.append(int(S[2:]))
    elif S == "3":
        print(dq.popleft() if len(dq) else -1)
    elif S == "4":
        print(dq.pop() if len(dq) else -1)
    elif S == "5":
        print(len(dq))
    elif S == "6":
        print(int(not len(dq)))
    elif S == "7":
        print(dq[0] if len(dq) else -1)
    elif S == "8":
        print(dq[-1] if len(dq) else -1)
