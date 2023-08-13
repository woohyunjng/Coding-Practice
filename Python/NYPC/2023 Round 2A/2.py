# 100 / 100

from math import gcd
from sys import stdin

T = int(stdin.readline())
for i in range(T):
    m, n = map(int, stdin.readline().rstrip().split())
    m %= n

    while n > 1:
        G = gcd(m, n)
        if G == 1:
            break
        while not n % G:
            n //= G
    else:
        print("YES")
        continue
    print("NO")
