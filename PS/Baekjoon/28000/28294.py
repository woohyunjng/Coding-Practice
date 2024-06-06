MOD = 10**9 + 7


def pow(A, B):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


N, a = map(int, input().split())
X, Y = pow(N, a), pow(N - 1, a)
print((N * Y + (X - Y) * (N - 1) * N) % MOD)
