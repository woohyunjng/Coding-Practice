from sys import stdin
from decimal import Decimal, getcontext
from math import ceil, floor

getcontext().prec = 100


def quadratic_formula(A, B, C):
    if B**2 - 4 * A * C < 0:
        return None
    val = (B**2 - 4 * A * C).sqrt()
    return ((-B - val) / (A * 2), (-B + val) / (A * 2))


def find(func, st, en, d):
    st, en = Decimal(ceil(st)), Decimal(floor(en))

    while st <= en:
        mid = (st + en) // Decimal(2)
        val = func(mid)

        if val == 0:
            return mid
        elif val > 0:
            if d:
                en = mid - 1
            else:
                st = mid + 1
        else:
            if d:
                st = mid + 1
            else:
                en = mid - 1

    return None


r = lambda x: round(x, 12)
A0, A1 = Decimal(-(10**6) - 1), Decimal(10**6 + 1)

N = int(stdin.readline())
for i in range(N):
    A, B, C, D = map(Decimal, stdin.readline().rstrip().split())
    res = []

    if A < 0:
        A, B, C, D = -A, -B, -C, -D

    f = lambda x: r(A * x**3) + r(B * x**2) + r(C * x) + r(D)

    if B**2 - 3 * A * C <= 0:
        res = [find(f, A0, A1, 1)]
    else:
        M, N = quadratic_formula(A * 3, B * 2, C)

        arr = [(A0, M, True), (M, N, False), (N, A1, True)]
        for j in arr:
            k = find(f, *j)
            if k != None:
                res = [k]
                break

        rest = quadratic_formula(
            A, r(A * res[0]) + B, r(A * res[0] ** 2) + r(B * res[0]) + C
        )
        if rest != None:
            for j in rest:
                res.append(j)

        res = list(sorted(set(res)))

    for j in res:
        print(j, end=" ")
    print()
