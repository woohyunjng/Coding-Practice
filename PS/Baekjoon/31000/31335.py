from random import randint
from math import gcd
from collections import defaultdict


def kpow(A, B):
    res = 1
    while B:
        if B % 2:
            res = res * A
        B >>= 1
        A = A**2
    return res


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


N, M = map(int, input().split())
if N == 1:
    print(-1)
    exit()

A = N
arr = []

while A > 1:
    arr.append(pollard_rho(A))
    A //= arr[-1]

checked = defaultdict(int)
for i in arr:
    checked[i] += 1

checked = dict(checked)
primes = sorted(checked.keys())
exponents = [checked[p] for p in primes]

for i in range(len(primes) - 1, -1, -1):
    exponents[i] += 1
    k = 1
    for j in range(len(primes)):
        if j > i:
            k *= primes[j]
        else:
            k *= kpow(primes[j], exponents[j])
    if k <= M:
        break
    exponents[i] -= 1
else:
    print(-1)
    exit()
print(k)
