A, B = map(int, input().split())
mx = 0
for i in range(min(A, B), max(A, B) + 1):
    val, k = i, 1
    while val > 1:
        if val % 2:
            val = val * 3 + 1
        else:
            val //= 2
        k += 1
    mx = max(mx, k)
print(mx)
