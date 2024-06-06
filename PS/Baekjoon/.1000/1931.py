N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

arr = list(sorted(arr, key=lambda x: (x[1], x[0])))
res = 1
last = arr[0][1]

for i in range(1, N):
    if arr[i][0] >= last:
        res += 1
        last = arr[i][1]

print(res)
