from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, M, R, C = map(int, input().split())
    res = 0

    res += (N - R) * M
    res += (N - R) * (M - 1) + (M - C)

    print(res)
