from math import gcd

A, B = map(int, input().split())
B //= A

for i in range(round(B ** 0.5), 0, -1):
    if i ** 2 > B or B % i:
        continue

    if gcd(i, B // i) == 1:
        print(A * i, A * B // i)
        break
