from collections import deque

N = int(input())
s = deque([])
res = 0

for i in range(N):
    h = int(input())

    while len(s):
        if s[-1] <= h:
            s.pop()
        else:
            s.append(h)
            break

    if not s:
        s.append(h)

    res += len(s) - 1

print(res)
