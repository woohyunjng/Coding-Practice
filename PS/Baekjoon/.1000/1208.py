from collections import defaultdict


def half_sum(arr):
    lst = []
    res = defaultdict(int)
    new_res = defaultdict(int)

    for i in arr:
        ims = []

        for j in lst:
            if not new_res[i + j]:
                ims.append(i + j)
            new_res[i + j] += res[j]
        for j in ims:
            lst.append(j)

        if not new_res[i]:
            lst.append(i)
        new_res[i] += 1

        res, new_res = new_res.copy(), new_res.copy()

    return res


N, S = map(int, input().split())
arr = list(map(int, input().split()))

left = half_sum(arr[: N // 2])
right = half_sum(arr[N // 2 :])

res = 0
left[0] += 0
right[0] += 0

for i in left.keys():
    if i != 0 and S - i != 0:
        res += left[i] * right[S - i]
    elif i != 0:
        res += left[i] * (right[S - i] + 1)
    elif S - i != 0:
        res += (left[i] + 1) * right[S - i]
    else:
        res += (left[i] + 1) * (right[S - i] + 1) - 1

print(res)
