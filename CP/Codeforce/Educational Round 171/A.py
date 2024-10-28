from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    X, Y, K = map(int, input().split())

    if X <= Y:
        print(0, 0, X, X)
        print(X, 0, 0, X)
    else:
        print(0, 0, Y, Y)
        print(Y, 0, 0, Y)
