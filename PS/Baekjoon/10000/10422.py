from math import comb

T = int(input())
for i in range(T):
    N = int(input())
    if N % 2:
        print(0)
    else:
        N //= 2
        print(comb(2 * N, N) // (N + 1) % (10**9 + 7))
