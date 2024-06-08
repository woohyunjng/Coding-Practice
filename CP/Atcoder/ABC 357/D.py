N = input()
K = len(N)
N = int(N)

MOD = 998244353


def fpow(A, B):
    res = 1
    while B:
        if B & 1:
            res = res * A % MOD
        B >>= 1
        A = A * A % MOD
    return res


print((fpow(10, N * K) - 1) * fpow(fpow(10, K) - 1, MOD - 2) * N % MOD)
