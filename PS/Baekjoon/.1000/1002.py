T = int(input())

for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    dis = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

    if not dis and r1 == r2:
        print(-1)
        continue

    if dis > r1 + r2:
        res = 0
    elif dis == r1 + r2:
        res = 1
    elif dis > max(r1, r2) - min(r1, r2):
        res = 2
    elif dis == max(r1, r2) - min(r1, r2):
        res = 1
    elif dis < max(r1, r2) - min(r1, r2):
        res = 0

    print(res)
