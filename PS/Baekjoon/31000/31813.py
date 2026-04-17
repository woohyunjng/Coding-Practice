T = int(input())
for i in range(T):
    N, K = map(int, input().split())
    res = []
    while K:
        N = len(str(K))
        i = (10**N - 1) // 9
        if K >= i:
            res.append(i * (K // i))
            K %= i
        else:
            i = 10 ** (N - 1) - 1
            res.append(i)
            K -= i
    print(len(res))
    print(*res)
