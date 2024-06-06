from heapq import heappush, heappop
from sys import stdin

N = int(stdin.readline())
heap = []

for i in range(N):
    A = int(stdin.readline())

    if not A:
        try:
            print(heappop(heap))
        except IndexError:
            print(0)
    else:
        heappush(heap, A)
