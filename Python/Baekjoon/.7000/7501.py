def pow(A, B, MOD):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


A, B = map(int, input().split())
base = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

for i in range(A, B + 1):
    if not i % 2:
        continue

    if i == 9:
        print(9, end=" ")
        continue

    d, K = i - 1, 0
    while not d % 2:
        d >>= 1
        K += 1

    for j in base:
        if i == j:
            continue

        M = pow(j, d, i)
        if M in [1, i - 1]:
            continue

        for k in range(K - 1):
            M = pow(M, 2, i)
            if M == i - 1:
                break
        else:
            break
    else:
        print(i, end=" ")
