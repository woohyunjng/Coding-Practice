from heapq import heappush, heappop

N, M, K, X = map(int, input().split())
graph = [[] for i in range(N + 1)]

for i in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)

q = []
heappush(q, (0, X))

dis = [1e9 for i in range(N + 1)]
dis[X] = 0

while len(q):
    p = heappop(q)
    if dis[p[1]] < p[0]:
        continue

    for i in graph[p[1]]:
        if p[0] + 1 < dis[i]:
            dis[i] = p[0] + 1
            heappush(q, (p[0] + 1, i))

check = False
for i in range(1, N + 1):
    if dis[i] == K:
        print(i)
        check = True
if not check:
    print(-1)
