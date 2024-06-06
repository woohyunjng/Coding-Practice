from decimal import Decimal, getcontext
from sys import stdin

T = int(stdin.readline())
getcontext().prec = 31

for i in range(T):
    res = Decimal(0)

    while True:
        a = Decimal(stdin.readline())
        if not a:
            break
        res += a

    print(str(res).rstrip("0").rstrip("."))
