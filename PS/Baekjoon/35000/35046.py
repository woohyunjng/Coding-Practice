from math import gcd

W, H, D = map(int, input().split())
N = int(input())

if W * H * D % N != 0:
    print(-1)
else:
    Wc = gcd(N, W)
    N = N // Wc

    Hc = gcd(N, H)
    N = N // Hc

    Dc = gcd(N, D)
    N = N // Dc

    print(Wc - 1, Hc - 1, Dc - 1)
