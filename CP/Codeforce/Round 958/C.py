from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    res = []

    i = 1
    while i <= N:
        if N & i == i:
            res.append(N ^ i)
            if res[-1] == 0:
                res.pop()
        i <<= 1

    res = list(reversed(res))
    res.append(N)
    print(len(res))
    print(*res)
