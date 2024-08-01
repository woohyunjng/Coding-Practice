from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    A, B = map(int, input().split())
    N, M = map(int, input().split())

    if A < B:
        res = min(N // (M + 1) * M * A + (N % (M + 1)) * A, N * A)
    else:
        res = min(N * B, N // (M + 1) * M * A + (N % (M + 1)) * B)

    print(res)
