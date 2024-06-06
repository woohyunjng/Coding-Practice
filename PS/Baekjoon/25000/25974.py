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

factorial = [1]
for i in range(1, K + 2):
    factorial.append(factorial[-1] * i % MOD)

for i in range(1, K + 1):
    val = pow(N + 1, i + 1) - 1
    for j in range(i):
        val -= (
            factorial[i + 1]
            * pow(factorial[j] * factorial[i - j + 1], MOD - 2)
            * arr[j]
            % MOD
        )
    arr.append(val * pow(i + 1, MOD - 2) % MOD)

print(arr[-1])
