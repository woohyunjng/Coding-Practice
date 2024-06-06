from decimal import Decimal, getcontext, ROUND_HALF_UP
from math import floor, sin


def pi():
    getcontext().prec += 2  # extra digits for intermediate steps
    three = Decimal(3)  # substitute "three=3.0" for regular floats
    lasts, t, s, n, na, d, da = 0, three, 3, 1, 0, 0, 24
    while s != lasts:
        lasts = s
        n, na = n + na, na + 8
        d, da = d + da, da + 32
        t = (t * n) / d
        s += t
    getcontext().prec -= 2
    return +s


def sin(x):
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i - 1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s


getcontext().prec = 200
getcontext().rounding = ROUND_HALF_UP

A, B, C = map(Decimal, input().split())
p = pi()

n = (-B + C) / (2 * p * A) - Decimal(1) / Decimal(2)
if n % 1 == 0:
    n -= 1
else:
    n = floor(n)

st, en = (2 * (n - 2) - 1) * p, (2 * (n + 2) + 1) * p
while abs(st - en) >= 10 ** (-70):
    mid = (st + en) / Decimal(2)
    val = A * mid + B * sin(Decimal(mid % (2 * p))) - C
    if val >= 0:
        en = mid
    else:
        st = mid

print((st + en) / Decimal(2))
