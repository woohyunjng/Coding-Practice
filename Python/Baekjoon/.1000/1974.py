from bisect import bisect_left

T = int(input())
for i in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    lis = []
    X = []

    for i in arr:
        if not lis or lis[-1] < i:
            lis.append(i)
            X.append(len(lis) - 1)
        else:
            a = bisect_left(lis, i)
            lis[a] = i
            X.append(a)

    K = len(lis) - 1
    res = []

    for i in range(N - 1, -1, -1):
        if X[i] == K:
            K -= 1
            res.append(i + 1)

    print(len(res))
    print(" ".join(map(str, list(reversed(res)))))
