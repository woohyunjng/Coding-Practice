from sys import setrecursionlimit

setrecursionlimit(10**6)


def get(K):
    if not K:
        return 0
    return get(K // 10) + 1


N = int(input())
print(get(N))
