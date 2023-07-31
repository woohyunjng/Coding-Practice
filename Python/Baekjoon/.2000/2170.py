from sys import stdin

N = int(stdin.readline().rstrip())
arr = []

for i in range(N):
    x, y = map(int, stdin.readline().rstrip().split())
    arr.append((x, y))

arr = list(sorted(arr, key=lambda x: x[0]))

start, end = arr[0]
res = 0

for i in range(1, N):
    if arr[i][0] <= end:
        end = max(end, arr[i][1])
    else:
        res += end - start
        start, end = arr[i][0], arr[i][1]

print(res + end - start)
