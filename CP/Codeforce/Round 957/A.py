from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    A, B, C = map(int, input().rstrip().split())
    res = 0
    for i in range(6):
        for j in range(6 - i):
            k = 5 - i - j
            res = max(res, (A + i) * (B + j) * (C + k))
    print(res)
