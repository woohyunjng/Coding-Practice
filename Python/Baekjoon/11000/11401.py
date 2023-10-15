N, K = map(int, input().split())
MOD = 10**9 + 7

factorial = [1]
for i in range(1, N + 1):
    factorial.append(factorial[-1] * i % MOD)

num, don = factorial[N], factorial[N - K] * factorial[K] % MOD

res, A = 1, MOD - 2
while A:
    if A % 2:
        res = res * don % MOD
    A >>= 1
    don = don**2 % MOD

print(num * res % MOD)
