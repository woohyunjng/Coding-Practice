from sys import stdin
from heapq import heappop, heappush

N = int(stdin.readline().rstrip())
arr = []

for i in range(N):
    arr.append(tuple(map(int, stdin.readline().rstrip().split())))
arr = list(sorted(arr))

q = []
heappush(q, arr[0][1])

for i in range(1, N):
    p = heappop(q)
    if arr[i][0] < p:
        heappush(q, p)
        heappush(q, arr[i][1])
    else:
        heappush(q, arr[i][1])

print(len(q))
