from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N, M, K = map(int, stdin.readline().rstrip().split())
    arr = list(map(int, stdin.readline().rstrip().split()))

    sorted_arr = [(arr[i], i) for i in range(N)]
    sorted_arr = list(sorted(sorted_arr, key=lambda x: (x[0], -x[1])))

    buy = [0 for i in range(N)]
    for i, j in sorted_arr:
        buy[j] = min(M, K)
        K -= buy[j]

    res, up = 0, 0
    for i in range(N):
        res += (arr[i] + up) * buy[i]
        up += buy[i]

    print(res)
