from heapq import heappop, heappush

N, M, X = map(int, input().split())
graph = [[] for i in range(N + 1)]

for i in range(M):
    A, B, T = map(int, input().split())
    graph[A].append((B, T))


def dijkstra(S):
    q = []
    heappush(q, (0, S))

    dis = [1e9 for i in range(N + 1)]
    dis[S] = 0

    while len(q):
        i, j = heappop(q)
        for x, y in graph[j]:
            if i + y < dis[x]:
                dis[x] = i + y
                heappush(q, (dis[x], x))

    return dis


real_dis = [0 for i in range(N + 1)]
for i in range(1, N + 1):
    d = dijkstra(i)
    real_dis[i] = d[X]

from_dis = dijkstra(X)
for i in range(1, N + 1):
    real_dis[i] += from_dis[i]

print(max(real_dis))
