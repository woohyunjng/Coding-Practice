from sys import stdin

T = int(stdin.readline())
for t in range(T):
    x, y = map(int, stdin.readline().rstrip().split())
    K = x ^ y
    res = 0

    while not (K & 1):
        res += 1
        K >>= 1
    print(1 << res)
