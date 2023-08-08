# 64 / 100

from collections import defaultdict


def arr_to_str(arr):
    res = ""
    for i in range(7):
        if i in arr:
            res += "1"
        else:
            res += "0"
    return res


def case(first):
    if first == "0000000":
        return defaultdict(lambda: set([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))

    arr = [
        set([0, 1, 2, 3, 4, 5]),
        set([1, 2]),
        set([0, 1, 3, 4, 6]),
        set([0, 1, 2, 3, 6]),
        set([1, 2, 5, 6]),
        set([0, 2, 3, 5, 6]),
        set([0, 2, 3, 4, 5, 6]),
        set([0, 1, 2]),
        set([0, 1, 2, 3, 4, 5, 6]),
        set([0, 1, 2, 3, 5, 6]),
    ]

    res = set([])

    for i in range(7):
        if first[i] == "1":
            res.add(i)

    case = defaultdict(set)
    for i in range(10):
        a = res & arr[i]
        b = list(arr[i] - a)
        c = [[list(a), 0] for i in a]

        while len(c):
            d = c.pop()
            if d[1] >= len(b):
                case[arr_to_str(d[0])].add(i)
                continue
            c.append([d[0] + [b[d[1]]], d[1] + 1])
            c.append([d[0], d[1] + 1])

    return case


A, B = input().split()
A, B = case(A), case(B)

T = int(input())

arr, res = [], []
for i in range(T):
    arr.append(defaultdict(bool))
    x, y = input().split()
    x_c, y_c = A[x], B[y]
    for j in x_c:
        for k in y_c:
            arr[i][10 * j + k] = True
            if i == 0:
                res.append(10 * j + k)

for i in range(1, T):
    new_res = []
    for j in res:
        if j - 1 < T - i:
            continue

        if arr[i][j - 1]:
            new_res.append(j - 1)
    res = new_res.copy()

res = list(
    filter(lambda x: int(x) >= T, map(lambda x: str(x + T - 1), sorted(list(set(res)))))
)
print(len(res))
if res:
    print(" ".join(res))
