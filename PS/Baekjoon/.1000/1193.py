X = int(input())
i = 2

while True:
    if (i - 2) * (i - 1) // 2 < X <= i * (i - 1) // 2:
        break
    i += 1

X -= (i - 2) * (i - 1) // 2
print(f"{X}/{i - X}" if i % 2 else f"{i - X}/{X}")
