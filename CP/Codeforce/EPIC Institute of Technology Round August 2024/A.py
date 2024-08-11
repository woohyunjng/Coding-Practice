from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, M, K = map(int, input().split())
    print(min(N, K) * min(M, K))
