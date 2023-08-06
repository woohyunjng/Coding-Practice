from math import ceil

N, M = map(int, input().split())
A, B = 1e9, 1e9

for i in range(M):
    X, Y = map(int, input().split())
    A, B = min(A, X), min(B, Y)

print(min(ceil(N / 6) * A, (N // 6) * A + (N % 6) * B, N * B))
