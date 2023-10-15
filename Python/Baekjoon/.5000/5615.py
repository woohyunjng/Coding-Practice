from sys import stdin


def pow(A, B, MOD):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


N = int(stdin.readline())
base = [2, 7, 61]
res = 0

for i in range(N):
    A = int(stdin.readline()) * 2 + 1
    if not A % 2:
        res += A == 2
        continue

    d, k = A - 1, 0
    while not d % 2:
        d >>= 1
        k += 1

    for i in base:
        if A == i:
            continue

        M = pow(i, d, A)
        if M in [1, A - 1]:
            continue

        for j in range(k - 1):
            M = pow(M, 2, A)
            if M == A - 1:
                break
        else:
            break
    else:
        res += 1

print(res)
