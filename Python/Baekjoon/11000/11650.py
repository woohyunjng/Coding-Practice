N = int(input())
arr = []

for i in range(N):
    x, y = map(int, input().split())
    arr.append([x, y, (x + 100000) * 1000000 + y])

arr = list(sorted(arr, key=lambda x: x[2]))

for x, y, k in arr:
    print(x, y)
