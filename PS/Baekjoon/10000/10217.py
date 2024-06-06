from heapq import heappush, heappop
from sys import stdin, maxsize

INF = maxsize
stdin.readline()

N, M, K = map(int, stdin.readline().rstrip().split())
arr = [[] for i in range(N + 1)]

for i in range(K):
    u, v, c, d = map(int, stdin.readline().rstrip().split())
    arr[u].append((d, c, v))

for i in range(1, N + 1):
    arr[i] = list(sorted(arr[i]))

hp = []
heappush(hp, (0, 0, 1))

dis = [[INF for j in range(M + 1)] for i in range(N + 1)]
dis[1][0] = 0

while hp:
    A, B, C = heappop(hp)
    if dis[C][B] < A:
        continue

    if C == N:
        print(A)
        break

    for i, j, k in arr[C]:
        if j + B <= M and i + A < dis[k][j + B]:
            heappush(hp, (i + A, j + B, k))
            for x in range(j + B, M + 1):
                if dis[k][x] <= i + A:
                    break
                dis[k][x] = i + A
else:
    print("Poor KCM")
