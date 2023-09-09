from sys import stdin
from collections import deque

N, M = map(int, stdin.readline().rstrip().split())
A = list(map(int, stdin.readline().rstrip().split()))
B = list(map(int, stdin.readline().rstrip().split()))

A = deque(sorted(A))
B = deque(sorted(B))

res_A, res_B = 0, 0

while len(A):
    p = A.popleft()
    while len(A) and A[0] < p + 100:
        A.popleft()
    res_A += 1

while len(B):
    p = B.popleft()
    while len(B) and B[0] < p + 360:
        B.popleft()
    res_B += 1

print(res_A, res_B)
