N, M = map(int, input().split())
MOD = 998244353
res, K, cur = 0, 0, 1

while N and M:
    A = ((1 << K) % MOD) * ((N >> 1) % MOD) % MOD
    if N & 1:
        A = (A + cur % MOD) % MOD
        cur = (cur + (1 << K)) % MOD

    if M & 1:
        res = (res + A) % MOD

    N >>= 1
    M >>= 1
    K += 1

print(res)
