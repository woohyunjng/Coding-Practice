from heapq import heappop, heappush

N = int(input())
M = int(input())
arr = [[] for i in range(N + 1)]

for i in range(M):
    X, Y, Z = map(int, input().split())
    arr[X].append((Z, Y))

A, B = map(int, input().split())

q = []
heappush(q, (0, A))

dis = [1e9 for i in range(N + 1)]
dis[A] = 0

while len(q):
    i, j = heappop(q)
    if dis[j] < i:
        continue

    for x, y in arr[j]:
        if i + x < dis[y]:
            dis[y] = i + x
            heappush(q, (i + x, y))

print(dis[B])
