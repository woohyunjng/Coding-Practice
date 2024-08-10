from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    X, Y, K = map(int, input().split())
    if K & 1:
        print(X, Y)
        K -= 1

    for i in range(1, K // 2 + 1):
        print(X + i, Y + i)
        print(X - i, Y - i)
