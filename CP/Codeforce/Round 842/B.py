from sys import stdin
from math import ceil

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().rstrip().split())
    arr = list(map(int, input().rstrip().split()))

    cur = 1
    res = 0
    for i in range(N):
        if arr[i] == cur:
            cur += 1
            res += 1

    print(ceil((N - res) / K))
