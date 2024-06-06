from math import acos, pi

x1, y1, r1, x2, y2, r2 = map(float, input().split())
d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

if abs(r1 - r2) >= d:
    print(round(min(r1, r2) ** 2 * pi * 1000) / 1000)
    exit()

if d >= r1 + r2:
    print("0.000")
    exit()

cos1 = (r1**2 + d**2 - r2**2) / (2 * r1 * d)
cos2 = (r2**2 + d**2 - r1**2) / (2 * r2 * d)

print(
    round(
        (r1**2 * acos(cos1) + r2**2 * acos(cos2) - (1 - cos1**2) ** 0.5 * r1 * d)
        * 1000
    )
    / 1000
)
