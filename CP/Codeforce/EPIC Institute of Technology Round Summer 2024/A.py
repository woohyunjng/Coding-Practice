from sys import stdin
from math import ceil

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().split())
    print((N - 1) * K + 1)
