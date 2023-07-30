from fractions import Fraction

P1 = list(map(int, input().split()))
P2 = list(map(int, input().split()))
P3 = list(map(int, input().split()))
S = (
    P1[0] * P2[1]
    + P2[0] * P3[1]
    + P3[0] * P1[1]
    - P2[0] * P1[1]
    - P3[0] * P2[1]
    - P1[0] * P3[1]
)

if S == 0:
    print(0)
else:
    print(S // abs(S))
