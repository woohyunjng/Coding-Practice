from sys import stdin
from collections import deque

N, M = map(int, stdin.readline().rstrip().split())
graph = [[[] for j in range(M + 1)] for i in range(N + 1)]
arr = []

for i in range(N):
    arr.append(list(input()))

if (N + M) % 2:
    print("NO SOLUTION")
    exit()

for i in range(N):
    for j in range(M):
        graph[i][j].append([(i + 1, j + 1), int(arr[i][j] != "\\")])
        graph[i + 1][j + 1].append([(i, j), int(arr[i][j] != "\\")])
        graph[i + 1][j].append([(i, j + 1), int(arr[i][j] != "/")])
        graph[i][j + 1].append([(i + 1, j), int(arr[i][j] != "/")])

dq = deque([((0, 0), 0)])

dis = [[1e9 for j in range(M + 1)] for i in range(N + 1)]
dis[0][0] = 0

while len(dq):
    x, i = dq.popleft()
    for y, j in graph[x[0]][x[1]]:
        if i + j < dis[y[0]][y[1]]:
            dis[y[0]][y[1]] = i + j
            if j == 0:
                dq.appendleft((y, i))
            else:
                dq.append((y, i + 1))

print(dis[N][M])
