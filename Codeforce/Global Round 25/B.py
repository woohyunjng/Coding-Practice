from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N, K = map(int, stdin.readline().rstrip().split())
    K -= 1
    res_1 = -1

    arr = list(map(int, stdin.readline().rstrip().split()))

    for i in range(K):
        if arr[i] > arr[K]:
            arr[i], arr[K] = arr[K], arr[i]
            K = i
            res_1 = i - 1
            break
    else:
        arr[0], arr[K] = arr[K], arr[0]
        K = 0

    if K == 0:
        res_2 = -1
    else:
        res_2 = 0

    for i in range(K, N):
        if arr[i] > arr[K]:
            break
        res_2 += 1

    print(max(res_1, res_2))
