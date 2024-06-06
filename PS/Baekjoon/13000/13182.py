from fractions import Fraction as Ft


def pw(a, b):
    return pow(a, b, 1000000007)


T = int(input())
for _ in range(T):
    R, G, B, K = map(int, input().split())
    res = K + (1 - Ft(pw(B, K), pw(B + 1, K))) * R + Ft(G * K, B)
    print(res.numerator * pw(res.denominator, -1) % 1000000007)
