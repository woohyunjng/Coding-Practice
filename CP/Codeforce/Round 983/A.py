from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    X = A.count(0)
    Y = 2 * N - X

    print(Y % 2, min(X, Y))
