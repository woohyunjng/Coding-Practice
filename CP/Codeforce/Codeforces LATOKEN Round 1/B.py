from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))

    before = 0

    res = 0
    for i in range(N):
        res += abs(arr[i] - before)
        before = arr[i]
    res += before

    if N == 1:
        res >>= 1
        print(res)
        continue

    res -= max(0, arr[0] - arr[1])
    arr[0] = min(arr[1], arr[0])

    for i in range(1, N - 1):
        if arr[i - 1] >= arr[i] or arr[i] <= arr[i + 1]:
            continue
        K = max(arr[i - 1], arr[i + 1])
        res -= max(0, arr[i] - K)
        arr[i] = K

    if arr[N - 1] >= arr[N - 2]:
        res -= arr[N - 1] - arr[N - 2]
        arr[N - 1] = arr[N - 2]

    print(res)
