from sys import stdin
from heapq import heappop, heappush


def dijkstra(graph, A, B, N):
    q = []
    heappush(q, (0, A))

    dis = [1e9 for i in range(N + 1)]
    dis[A] = 0

    while len(q):
        i, j = heappop(q)
        for x, y in graph[j]:
            if i + x < dis[y]:
                dis[y] = i + x
                heappush(q, (i + x, y))

    return dis[B]


N, E = map(int, stdin.readline().rstrip().split())
graph = [[] for i in range(N + 1)]

for i in range(E):
    a, b, c = map(int, stdin.readline().rstrip().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

v1, v2 = map(int, stdin.readline().rstrip().split())

res = min(
    dijkstra(graph, 1, v1, N) + dijkstra(graph, v1, v2, N) + dijkstra(graph, v2, N, N),
    dijkstra(graph, 1, v2, N) + dijkstra(graph, v2, v1, N) + dijkstra(graph, v1, N, N),
)

print(res if res < 1e9 else -1)
