N = int(input())
arr = []

for i in range(N):
    x, y = map(int, input().split())
    arr.append([x, y, (y + 100000) * 1000000 + x])

arr = list(sorted(arr, key=lambda x: x[2]))

for x, y, k in arr:
    print(x, y)
