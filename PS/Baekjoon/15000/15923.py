N = int(input())
a, b, c, d = 1e9, 0, 1e9, 0

for i in range(N):
    x, y = map(int, input().split())
    a, b = min(a, x), max(b, x)
    c, d = min(c, y), max(d, y)

print((b + d - a - c) * 2)
