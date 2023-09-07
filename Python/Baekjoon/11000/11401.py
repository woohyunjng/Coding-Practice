MOD = 10**9 + 7


def pw(A, B):
    if B == 0:
        return 1

    if B % 2:
        return pw(A, B // 2) ** 2 * A % MOD
    else:
        return pw(A, B // 2) ** 2 % MOD


N, K = map(int, input().split())

fac = 1
res = 1

for i in range(1, N + 1):
    res = res * i % MOD
    if i == N - K:
        fac = res * fac % MOD
    if i == K:
        fac = res * fac % MOD

print(res * pw(fac, MOD - 2) % MOD)
