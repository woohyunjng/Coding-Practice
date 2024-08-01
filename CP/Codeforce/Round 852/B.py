from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    X, Y = map(int, input().split())
    N = (X - Y) * 2
    arr = [0] * N

    arr[0] = X
    for i in range(1, N // 2 + 1):
        arr[i] = arr[i - 1] - 1
    for i in range(N // 2 + 1, N):
        arr[i] = arr[i - 1] + 1

    print(N)
    print(*arr)
