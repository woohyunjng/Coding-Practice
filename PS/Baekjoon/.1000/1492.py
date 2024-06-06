from math import comb

MOD = 10**9 + 7


def pow(A, B):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


N, K = map(int, input().split())
arr = [N]

for i in range(1, K + 1):
    val = pow(N + 1, i + 1) - 1
    for j in range(i):
        val -= comb(i + 1, j) * arr[j] % MOD
    arr.append(val * pow(i + 1, MOD - 2) % MOD)

print(arr[-1])
