from collections import deque
from sys import stdin

N = int(stdin.readline())
q = deque([])

for i in range(N):
    S = stdin.readline().rstrip()
    if S.startswith("push "):
        q.append(int(S[5:]))
    elif S == "pop":
        print(q.popleft() if len(q) else -1)
    elif S == "size":
        print(len(q))
    elif S == "empty":
        print(int(not len(q)))
    elif S == "front":
        print(q[0] if len(q) else -1)
    elif S == "back":
        print(q[-1] if len(q) else -1)
