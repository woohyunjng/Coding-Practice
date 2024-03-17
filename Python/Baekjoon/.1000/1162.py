from heapq import heappop, heappush

N, M, K = map(int, input().split())
arr = [[] for i in range(N + 1)]

for i in range(M):
    A, B, C = map(int, input().split())
    arr[A].append((C, B))
    arr[B].append((C, A))

hp = []
heappush(hp, (0, 1, 0))

dis = [[10**11 for j in range(K + 1)] for i in range(N + 1)]
dis[1][0] = 0

while len(hp):
    i, j, k = heappop(hp)
    if dis[j][k] < i:
        continue

    for x, y in arr[j]:
        if i + x < dis[y][k]:
            dis[y][k] = i + x
            heappush(hp, (i + x, y, k))
        if k < K and i < dis[y][k + 1]:
            dis[y][k + 1] = i
            heappush(hp, (i, y, k + 1))

print(min(dis[N]))
