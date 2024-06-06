from collections import deque

N = int(input())
A = list(map(int, input().split()))
K = 1
dq = deque([])

for i in reversed(A):
    if i == 1:
        dq.appendleft(K)
    elif i == 2:
        j = dq.popleft()
        dq.appendleft(K)
        dq.appendleft(j)
    else:
        dq.append(K)
    K += 1

print(*dq)
