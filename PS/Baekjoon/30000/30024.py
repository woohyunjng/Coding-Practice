from sys import stdin
from heapq import heappop, heappush, heapify

N, M = map(int, stdin.readline().rstrip().split())
arr = []

for i in range(N):
    arr.append(list(map(int, stdin.readline().rstrip().split())))

K = int(stdin.readline())
avail = set([])
visited = [[False for j in range(M)] for i in range(N)]

for i in range(N):
    avail.add((-arr[i][0], i, 0))
    avail.add((-arr[i][M - 1], i, M - 1))

for i in range(M):
    avail.add((-arr[0][i], 0, i))
    avail.add((-arr[N - 1][i], N - 1, i))

avail = list(avail)
heapify(avail)

for i in range(K):
    mx = -1

    while True:
        k, x, y = heappop(avail)
        if visited[x][y]:
            continue

        visited[x][y] = True
        print(x + 1, y + 1)
        break

    A = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
    ims = []

    for x, y in A:
        if x < 0 or x >= N or y < 0 or y >= M or visited[x][y]:
            continue
        heappush(avail, (-arr[x][y], x, y))
