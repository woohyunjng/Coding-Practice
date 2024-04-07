from bisect import bisect_left
from sys import stdin

town, aSum, axSum = [], [0], [0]
N, Q = map(int, stdin.readline().split())

for _ in range(N):
    a, x = map(int, stdin.readline().split())
    town.append([a, x])
town.sort(key=lambda k: k[1])

for i in range(N):
    aSum.append(aSum[-1] + town[i][0])
    axSum.append(axSum[-1] + town[i][0] * town[i][1])

for _ in range(Q):
    qj = int(stdin.readline())
    x = bisect_left(town, qj, key=lambda k: k[1])
    print(qj * (2 * aSum[x] - aSum[N]) - (2 * axSum[x] - axSum[N]))
