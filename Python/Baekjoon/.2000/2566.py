mx, a, b = -1, 0, 0

for i in range(1, 10):
    arr = list(map(int, input().split()))
    for j in range(1, 10):
        if arr[j - 1] >= mx:
            mx = arr[j - 1]
            a, b = i, j

print(mx)
print(a, b)
