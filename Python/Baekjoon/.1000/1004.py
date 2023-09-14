T = int(input())

for i in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    N = int(input())
    res = 0

    for j in range(N):
        x, y, r = map(int, input().split())

        if (x - x1) ** 2 + (y - y1) ** 2 < r**2:
            res += 1
        if (x - x2) ** 2 + (y - y2) ** 2 < r**2:
            res += 1
        if (x - x1) ** 2 + (y - y1) ** 2 < r**2 and (x - x2) ** 2 + (y - y2) ** 2 < r**2:
            res -= 2

    print(res)
