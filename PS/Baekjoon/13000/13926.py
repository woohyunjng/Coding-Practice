from random import randint
from math import gcd
from collections import defaultdict


def pow(A, B, MOD):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


def is_prime(N):
    if not N % 2:
        return N == 2

    d, k = N - 1, 0
    while not d % 2:
        d >>= 1
        k += 1

    base = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
    for i in base:
        if not N % i:
            return N == i

        M = pow(i, d, N)
        if M in [1, N - 1]:
            continue

        for j in range(k - 1):
            M = pow(M, 2, N)
            if M == N - 1:
                break
        else:
            break
    else:
        return True
    return False


def pollard_rho(N):
    if is_prime(N):
        return N
    if N == 1:
        return 1
    if not N % 2:
        return 2

    A, B = randint(1, N), 1
    f = lambda x: (x**2 % N + A + N) % N

    x = randint(2, N)
    y = x

    while B == 1:
        x, y = f(x), f(f(y))
        B = gcd(abs(x - y), N)

        if B == N:
            return pollard_rho(N)

    if is_prime(B):
        return B
    return pollard_rho(B)


N = int(input())
A = N
arr = []

while A > 1:
    arr.append(pollard_rho(A))
    A //= arr[-1]

checked = defaultdict(bool)
for i in arr:
    if checked[i]:
        continue
    checked[i] = True
    N = N // i * (i - 1)

print(N)
