from math import gcd

A1, B1 = map(int, input().split())
A2, B2 = map(int, input().split())

B = B1 * B2
A = A1 * B2 + A2 * B1
G = gcd(A, B)

print(A // G, B // G)
