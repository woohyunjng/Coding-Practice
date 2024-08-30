from sys import stdin
from math import ceil

input = stdin.readline
T = int(input())

for t in range(T):
    L, R = map(int, input().split())
    odd = 0

    if L & 1 and R & 1:
        odd = (R - L) // 2 + 1
    elif L & 1 or R & 1:
        odd = (R - L + 1) // 2
    else:
        odd = ((R - L - 2) // 2 + 1) if R > L else 0

    even = R - L + 1 - odd
    res = min(even, odd // 2)

    print(res)
