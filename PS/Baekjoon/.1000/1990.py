A, B = map(int, input().split())
B = min(B, 10000000)
checked = [False for i in range((B + 1 // 2))]

for i in range(3, int(B**0.5) + 1, 2):
    if checked[(i - 1) // 2]:
        continue

    for j in range(i * 3, B + 1, i * 2):
        checked[(j - 1) // 2] = True

for i in range(A, B + 1):
    if (i != 2 and not i % 2) or checked[(i - 1) // 2]:
        continue

    j = str(i)
    if j == j[::-1]:
        print(i)

print(-1)
