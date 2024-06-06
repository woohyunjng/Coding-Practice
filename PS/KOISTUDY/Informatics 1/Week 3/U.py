from math import ceil

A, B = map(int, input().split())
print((B - int(B**0.5)) - (A - ceil(A**0.5)))
