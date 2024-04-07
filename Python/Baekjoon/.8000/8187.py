from random import randint
from sys import stdin
from math import gcd
from collections import defaultdict


def pow(A, B, MOD=None):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD if MOD else res * A
        B >>= 1
        A = A**2 % MOD if MOD else A**2
    return res


def is_prime(N):
    if not N % 2:
        return N == 2

    d, k = N - 1, 0
    while not d % 2:
        d >>= 1
        k += 1

    base = [2, 7, 61]
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
    if N == 1:
        return 1
    if not N % 2:
        return 2
    if is_prime(N):
        return N

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


N = int(stdin.readline())
A = list(map(int, stdin.readline().rstrip().split()))

factors = defaultdict(int)
mx, D = -1, 0

while A:
    i = A.pop()
    j = pollard_rho(i)
    factors[j] += 1

    if i != j:
        A.append(i // j)

    if factors[j] > mx:
        mx = factors[j]
        D = 1
    elif factors[j] == mx:
        D += 1

print(mx)
print(pow(2, D) - 1)
