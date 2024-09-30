from sys import stdin
from math import isqrt

input = stdin.readline
T = int(input())

for t in range(T):
    K = int(input())
    st, en, res = 1, 10**20, 0

    while st <= en:
        mid = (st + en) // 2
        val = mid - isqrt(mid)

        if val >= K:
            res = mid
            en = mid - 1
        else:
            st = mid + 1

    print(res)
