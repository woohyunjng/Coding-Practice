# 100 / 100

from sys import stdin

N = int(stdin.readline())
arr = []

for i in range(N):
    x, y = map(int, stdin.readline().rstrip().split())
    arr.append([x, y])

arr_y = list(sorted(arr, key=lambda k: k[1]))
for i in range(N):
    arr_y[i][1] = i

arr_x = list(map(lambda k: k[1], sorted(arr_y, key=lambda k: k[0])))
pl = [0 for i in range(N)]
for i in range(N):
    pl[arr_x[i]] = i

res = 0
for i in range(N):
    if arr_x[i] != i:
        x = pl[i]
        pl[i], pl[arr_x[i]] = i, x
        arr_x[i], arr_x[x] = i, arr_x[i]
        res += 1

print(res)
