from sys import stdin
from heapq import heappop, heappush

N = int(stdin.readline())
p = list(map(int, stdin.readline().rstrip().split()))
A = list(map(int, stdin.readline().rstrip().split()))

child = [[] for i in range(N + 1)]

for i in range(2, N + 1):
    child[p[i - 2]].append(i)

hp = []
heappush(hp, (-A[0], 1))

sm = 0

while len(hp):
    p, q = heappop(hp)
    sm += -p
    print(sm)

    for i in child[q]:
        heappush(hp, (-A[i - 1], i))
