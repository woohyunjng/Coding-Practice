# 979/1000

T = int(input())
for i in range(T):
    N = int(input())
    arr = list(map(int, input().split()))

    res = [N - arr[-1]]
    mn = res[0]

    for i in range(N - 2, -1, -1):
        res.append(mn - arr[i])
        mn = min(mn, res[-1])

    print(*reversed(res), sep=" ")
