from sys import stdin
from collections import deque

N, M = map(int, stdin.readline().rstrip().split())
A = list(map(int, stdin.readline().rstrip().split()))

dq = deque([])
for i in range(N - M):
    dq.append(A[i])

mx = A[N - M - 1] - A[0]
mn = A[0]

for i in range(N - M, N):
    dq.popleft()
    mn = min(mn, dq[0])
    dq.append(A[i])
    mx = max(A[i] - mn, mx)

print(mx)
