from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, X, Y = map(int, input().split())
    arr = [1] * (N + 1)

    for i in range(Y - 1, 0, -2):
        arr[i] = -1

    for i in range(X + 1, N + 1, 2):
        arr[i] = -1

    print(*arr[1:])
