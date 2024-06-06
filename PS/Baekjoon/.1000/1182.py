from collections import defaultdict


N, S = map(int, input().split())
arr = list(map(int, input().split()))

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

print(res[S])
