T = int(input())

for i in range(T):
    N = int(input())
    arr = []

    for i in range(N):
        A, B = map(int, input().split())
        arr.append((A, B))

    arr = list(sorted(arr, key=lambda x: x[0] * 100001 + x[1]))
    res, lst = 1, arr[0][1]
    for i in range(1, N):
        if arr[i][1] < lst:
            res += 1
            lst = arr[i][1]

    print(res)
