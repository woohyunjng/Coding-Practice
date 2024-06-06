from collections import deque
from sys import stdin

N = int(stdin.readline())
st = deque([])

for i in range(N):
    S = stdin.readline().rstrip()
    if S.startswith("1"):
        st.append(int(S[2:]))
    elif S == "2":
        print(st.pop() if len(st) else -1)
    elif S == "3":
        print(len(st))
    elif S == "4":
        print(int(len(st) == 0))
    elif S == "5":
        print(st[-1] if len(st) else -1)
