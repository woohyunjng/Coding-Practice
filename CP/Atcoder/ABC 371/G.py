from sys import stdin
from math import gcd


def extended_gcd(A, B):
    if B == 0:
        return A, 1, 0
    g, x1, y1 = extended_gcd(B, A % B)
    return g, y1, x1 - (A // B) * y1


def chinese_remainder_theorem(A, B, M, N):
    G = gcd(M, N)
    M_prime, N_prime = M // G, N // G
    diff = (B - A) // G
    _, x, _ = extended_gcd(M_prime, N_prime)
    mod = M_prime * N_prime * G
    rem = (A + (x * diff % N_prime) * M) % mod

    if rem < 0:
        rem += mod

    return rem, mod


input = stdin.readline

N = int(input())
P = [0] + list(map(int, input().split()))
A = [0] + list(map(int, input().split()))

to = [0] * (N + 1)
res = [0] * (N + 1)

for i in range(1, N + 1):
    to[P[i]] = i

rem = 0
mod = 1

for i in range(1, N + 1):
    if res[i] != 0:
        continue

    cycle_size = 0
    cnt = 0
    j = i
    while True:
        cycle_size += 1
        cnt += 1
        j = to[j]
        if j == i and cnt != 0:
            break

    min_val = 100000000000000
    K = -1
    cnt = 0
    G = gcd(mod, cycle_size)

    j = i
    while True:
        if (cnt - rem) % G == 0 and A[j] < min_val:
            min_val = A[j]
            K = j
            X = cnt
        cnt += 1
        j = to[j]
        if j == i and cnt != 0:
            break

    rem, mod = chinese_remainder_theorem(rem, X, mod, cycle_size)

    cnt = 0
    j = K
    k = i
    while True:
        res[k] = A[j]
        cnt += 1
        j = to[j]
        k = to[k]
        if j == K and cnt != 0:
            break

print(*res[1:])
