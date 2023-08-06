from heapq import heappop, heappush
from sys import stdin

N, K = map(int, stdin.readline().rstrip().split())
arr = []

for i in range(N):
    M, V = map(int, stdin.readline().rstrip().split())
    arr.append((M, V))

arr = list(sorted(arr, key=lambda x: x[0]))
res = 0

C = []
for i in range(K):
    C.append(int(stdin.readline()))
C = sorted(C)

bg = []
j = 0

for i in C:
    while j < N and arr[j][0] <= i:
        heappush(bg, -arr[j][1])
        j += 1
    if len(bg):
        res += -heappop(bg)

print(res)
