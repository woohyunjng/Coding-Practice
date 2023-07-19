from math import log10, floor

a, b = map(int, input().split())
print(floor(b * log10(a)) + 1)
