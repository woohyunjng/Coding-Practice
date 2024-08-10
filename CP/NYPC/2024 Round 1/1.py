from sys import stdin
from math import ceil

input = stdin.readline
T = int(input())

for t in range(T):
    A, B = map(int, input().split())
    X = ceil((A + B) / 4)

    if X > min(A, B):
        print(-1)
    else:
        print(X)
