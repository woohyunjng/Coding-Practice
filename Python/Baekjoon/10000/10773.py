from collections import deque

K = int(input())
a = deque([])

for i in range(K):
    N = int(input())
    if not N:
        a.pop()
    else:
        a.append(N)

print(sum(a))
