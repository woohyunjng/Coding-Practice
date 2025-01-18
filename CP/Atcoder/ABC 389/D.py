R = int(input())
res = 0

for i in range(1, R):
    res += int((R**2 - (i + 0.5) ** 2) ** 0.5 - 0.5)

print(4 * res + 4 * R - 3)
