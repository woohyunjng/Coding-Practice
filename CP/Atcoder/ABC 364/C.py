from sys import stdin

input = stdin.readline

N, X, Y = map(int, input().split())
A = list(map(int, input().rstrip().split()))
B = list(map(int, input().rstrip().split()))

res = 1000000000000000
x, y = 0, 0

arr = [(A[i], B[i]) for i in range(N)]

arr = list(sorted(arr, reverse=True))
val = 0

for i, j in arr:
    x += i
    y += j
    val += 1
    if x > X or y > Y:
        break

res = min(res, val)


arr = list(sorted(arr, key=lambda x: (x[1], x[0]), reverse=True))
val = 0
x, y = 0, 0

for i, j in arr:
    x += i
    y += j
    val += 1
    if x > X or y > Y:
        break

res = min(res, val)

print(res)
