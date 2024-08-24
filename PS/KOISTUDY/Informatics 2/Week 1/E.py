from fractions import Fraction

N = int(input())
res = Fraction(0, 1)

for i in range(N):
    A, B = map(int, input().split())
    res += Fraction(A, B)

print(res.numerator, res.denominator, sep="/")
