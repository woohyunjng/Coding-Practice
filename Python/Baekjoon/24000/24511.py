from collections import deque

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

M = int(input())
C = list(map(int, input().split()))

arr = deque([])
for i in range(N):
    if A[i] == 0:
        arr.append(B[i])

for i in C:
    arr.appendleft(i)
    print(arr.pop(), end=" ")
