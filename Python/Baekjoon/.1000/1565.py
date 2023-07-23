from math import lcm, gcd

size_d, size_m = map(int, input().split())
D = list(map(int, input().split()))
M = list(map(int, input().split()))
D, M = lcm(*D), gcd(*M)

if M % D:
    print(0)
else:
    res = 0
    N = M // D
    rt = round(N ** 0.5)
    
    for i in range(1, rt):
        if not N % i:
            res += 1

    res *= 2
    if rt ** 2 == N:
        res += 1
    print(res)
