from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    P1, P2, P3 = map(int, input().split())

    if (P1 + P2 + P3) & 1:
        print(-1)
    else:
        res = 0
        for i in range(31):
            for j in range(31):
                for k in range(31):
                    if i + j <= P1 and i + k <= P2 and j + k <= P3:
                        res = max(res, i + j + k)
        print(res)
