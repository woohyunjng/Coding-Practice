from heapq import heappop, heappush

V, E = map(int, input().split())
K = int(input())

graph = [[] for i in range(V + 1)]
for i in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))

q = []
heappush(q, (0, K))

dis = [1e9 for i in range(V + 1)]
dis[K] = 0

while len(q):
    i, j = heappop(q)
    for x, y in graph[j]:
        if i + x < dis[y]:
            dis[y] = i + x
            heappush(q, (dis[y], y))

for i in range(1, V + 1):
    print(dis[i] if dis[i] < 1e9 else "INF")
