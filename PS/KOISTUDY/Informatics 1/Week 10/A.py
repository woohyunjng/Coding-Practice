from sys import setrecursionlimit

setrecursionlimit(10**6)


def get(K):
    if K == 1:
        return 1
    return K + get(K - 1)


N = int(input())
print(get(N))
