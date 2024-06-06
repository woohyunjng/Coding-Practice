from sys import stdin
from math import gcd

T = int(stdin.readline())
for t in range(T):
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().rstrip().split()))
    LCM = arr[0]

    for i in range(1, N):
        G = gcd(LCM, arr[i])
        LCM = LCM * arr[i] // G

    res = [LCM // arr[i] for i in range(N)]
    if sum(res) >= LCM:
        print(-1)
    else:
        print(*res)
