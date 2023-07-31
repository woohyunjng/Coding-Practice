from math import ceil

X, Y, D, T = map(int, input().split())
dis = (X**2 + Y**2) ** 0.5

if T >= D:
    print(dis)
else:
    res = min(
        dis - D * (dis // D) + T * (dis // D),
        D * (dis // D + 1) - dis + T * (dis // D + 1),
    )
    if D <= dis:
        res = min(res, ceil(dis / D) * T)
    else:
        res = min(res, 2 * T)

    print(float(res))
