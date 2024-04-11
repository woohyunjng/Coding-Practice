from bisect import bisect_left


def reverse_bisect(a, x, lo=0, hi=None):
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] > x:
            lo = mid + 1
        else:
            hi = mid
    return lo


N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))
arr_1 = list(sorted(enumerate(arr), key=lambda x: (x[1][0], -x[1][1])))
arr_1 = list(map(lambda i: (i[1][1], i[0]), arr_1))

arr_2 = list(sorted(enumerate(arr), key=lambda x: x[1]))
arr_2 = list(map(lambda i: (i[1][1], i[0]), arr_2))

X = [[], [], [], []]
res = [[0, 0, 0, 0] for i in range(N)]

for i in arr_1:
    if not len(X[0]) or X[0][-1] < i[0]:
        X[0].append(i[0])
        res[i[1]][0] = len(X[0])
    else:
        bs = bisect_left(X[0], i[0])
        X[0][bs] = i[0]
        res[i[1]][0] = bs + 1

for i in arr_2:
    if not len(X[1]) or X[1][-1] > i[0]:
        X[1].append(i[0])
        res[i[1]][1] = len(X[1])
    else:
        bs = reverse_bisect(X[1], i[0])
        X[1][bs] = i[0]
        res[i[1]][1] = bs + 1

for i in reversed(arr_1):
    if not len(X[2]) or X[2][-1] > i[0]:
        X[2].append(i[0])
        res[i[1]][2] = len(X[2])
    else:
        bs = reverse_bisect(X[2], i[0])
        X[2][bs] = i[0]
        res[i[1]][2] = bs + 1

for i in reversed(arr_2):
    if not len(X[3]) or X[3][-1] < i[0]:
        X[3].append(i[0])
        res[i[1]][3] = len(X[3])
    else:
        bs = bisect_left(X[3], i[0])
        X[3][bs] = i[0]
        res[i[1]][3] = bs + 1

mx = 0
for i in range(N):
    if all([res[i][j] >= 2 for j in range(4)]):
        mx = max(mx, sum(res[i]) - 3)
print(N - mx if mx else -1)
