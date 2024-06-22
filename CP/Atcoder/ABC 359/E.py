from bisect import bisect_left

N = int(input())
res = []

H = list(map(lambda x: -int(x), input().split()))

res, X = [0], [(0, 0)] * N
mx = 0
for i in range(N):
    if mx == 0:
        res.append(H[i])
        X[0] = (H[i], i)
        mx += 1
    elif X[mx - 1][0] < H[i]:
        res.append(res[X[mx - 1][1] + 1] + (i - X[mx - 1][1]) * H[i])
        X[mx] = (H[i], i)
        mx += 1
    else:
        idx = bisect_left(X, (H[i], i), 0, mx - 1)
        if idx == 0:
            res.append(H[i] * (i + 1))
        else:
            res.append(res[X[idx - 1][1] + 1] + H[i] * (i - X[idx - 1][1]))
        X[idx] = (H[i], i)
        mx = idx + 1

for i in res[1:]:
    print(-i + 1, end=" ")
