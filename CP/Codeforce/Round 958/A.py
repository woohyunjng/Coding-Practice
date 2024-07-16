from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().split())
    res = 0

    while N > 1:
        N -= K - 1
        res += 1

    print(res)
