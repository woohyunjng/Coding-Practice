from sys import stdin

MOD = 10**9 + 7


def fpow(A, B):
    if B == 1:
        return 0
    res = 1
    while B:
        if B & 1:
            res = res * A % MOD
        A = A * A % MOD
        B >>= 1
    return res


input = stdin.readline

Q = int(input())
for i in range(Q):
    H, K = map(int, input().split())
    if H == 1:
        print(0)
        continue
    if K == 1:
        print((H + 1) * fpow(3, MOD - 2) % MOD)
        continue
    T = H * (K - 1) % MOD
    T = T * (fpow(K, H * 2) + fpow(K, H)) % MOD

    inv = fpow(K, H)
    inv = inv * (fpow(K, H) - 1 + MOD) % MOD
    inv = inv * (K + 1) % MOD

    T = (T - inv + MOD * 2) % MOD
    inv = (fpow(K, H) + MOD - 1) % MOD

    X = fpow(K - 1, MOD - 2)
    inv = inv * X % MOD
    inv = inv * (inv - 1 + MOD) * fpow(2, MOD - 2) % MOD
    inv = inv * fpow(K - 1, 3) % MOD
    inv = fpow(inv, MOD - 2)
    T = T * inv % MOD

    print(T)
