N = int(input())
arr = [True for i in range(N + 1)]

arr[0] = False
arr[1] = False
for i in range(N + 1):
    if not arr[i]:
        continue

    for j in range(i * 2, N + 1, i):
        arr[j] = False

res = 0
for i in range(N + 1):
    if arr[i]:
        res += i
print(res)
