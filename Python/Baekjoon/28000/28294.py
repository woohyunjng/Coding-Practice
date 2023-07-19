from sys import stdin


def new_pow(x, y):
    res = 1
    while y:
        if y % 2:
            res = res * x % 1000000007
        x *= x % 1000000007
        y //= 2
    return res


N, a = map(int, stdin.readline().rstrip().split())
pw = new_pow(N, a)
print((pw * N + N * (N - 2) * (pw - new_pow(N - 1, a))) % 1000000007)
