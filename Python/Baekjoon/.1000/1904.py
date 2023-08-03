N = int(input())
a, b = 1, 2

for i in range(3, N + 1):
    a, b = b, (a + b) % 15746

print(b if N >= 2 else 1)
