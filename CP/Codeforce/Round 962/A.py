from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    N //= 2
    if N % 2:
        print((N + 1) // 2)
    else:
        print(N // 2)
