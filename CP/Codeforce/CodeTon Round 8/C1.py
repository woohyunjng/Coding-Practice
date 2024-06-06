# 960/1250

T = int(input())

for i in range(T):
    N, X, Y = map(int, input().split())
    arr = list(sorted(map(int, input().split())))

    res = X - 2
    for j in range(1, X):
        if 2 == arr[j] - arr[j - 1]:
            res += 1

    if arr[-1] - arr[0] == N - 2:
        res += 1
    print(res)
