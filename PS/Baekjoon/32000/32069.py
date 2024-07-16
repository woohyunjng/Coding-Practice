from sys import stdin
from bisect import bisect_left

input = stdin.readline

L, N, K = map(int, input().rstrip().split())
A = list(map(int, input().rstrip().split()))

B = [A[0], L - A[-1]]
for i in range(N - 1):
    M = A[i + 1] - A[i] - 1
    B.append(M // 2)
    B.append(M - M // 2)
B = list(sorted(B))

arr = []
if K >= N:
    K -= N
    for i in range(N):
        arr.append(0)
else:
    for i in range(K):
        arr.append(0)
    K = 0
cur, num = len(B) - bisect_left(B, 1), 1

while K > 0:
    if K >= cur:
        K -= cur
        for i in range(cur):
            arr.append(num)
        num += 1
        M = bisect_left(B, num)
        cur = len(B) - M
    else:
        for i in range(K):
            arr.append(num)
        K = 0

print(*arr, sep="\n")
