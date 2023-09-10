from sys import stdin

S0, N, M = map(int, stdin.readline().rstrip().split())
arr = []

size = 0

for i in range(N + M):
    A = int(stdin.readline())
    if A:
        if size == S0:
            S0 *= 2
        size += 1
    else:
        size -= 1

print(S0)
