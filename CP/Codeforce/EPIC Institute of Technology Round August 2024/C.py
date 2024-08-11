from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = []

    for i in range(N):
        X, Y = map(int, input().split())
        arr.append((X, Y))

    XS, YS, XT, YT = map(int, input().split())

    res = True

    for i in range(N):
        x, y = arr[i]
        res = res and ((XT - x) ** 2 + (YT - y) ** 2 > (XS - XT) ** 2 + (YS - YT) ** 2)

    print("YES" if res else "NO")
