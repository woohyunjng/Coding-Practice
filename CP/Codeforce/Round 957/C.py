from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, M, K = map(int, input().rstrip().split())
    arr = list(range(N, K - 1, -1)) + list(range(M + 1, K)) + list(range(1, M + 1))
    print(*arr)
