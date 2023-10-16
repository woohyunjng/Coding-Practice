def pow(A, B, MOD):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


def factorial(A, MOD=False):
    if A == 0:
        return 0
    res = 1
    for i in range(2, A + 1):
        res = res * i % MOD if MOD else res * i
    return res


N, K, P = map(int, input().split())

if N == 2:
    print(2 % P)
elif N == 3:
    if K in [2, 3]:
        print(factorial(6 if K == 2 else 720, P))
    else:
        print(0)
elif N >= 13 or N >= P:
    print(0)
elif K >= 3:
    print(0)
elif N == 12:
    N = factorial(N)
    if N >= P:
        print(0)
    else:
        res = 1
        for i in range(P - 1, N, -1):
            res = res * i % P
        print(-1 * pow(res, P - 2, P) % P)
else:
    print(factorial(factorial(N), P))
