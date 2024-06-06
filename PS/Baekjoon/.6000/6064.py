from math import lcm, gcd

T = int(input())

for i in range(T):
    M, N, x, y = map(int, input().split())
    L, G = lcm(M, N), gcd(M, N)

    K = x
    while K <= M * N:
        if not (K - y) % N:
            break
        K += M
    else:
        print("-1")
        continue

    print(K)
