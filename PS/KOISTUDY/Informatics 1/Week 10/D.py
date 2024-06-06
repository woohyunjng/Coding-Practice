from sys import setrecursionlimit

setrecursionlimit(10**6)


def get(K):
    if K == 1:
        return 1
    if K % 2:
        return get(3 * K + 1) + 1
    else:
        return get(K // 2) + 1


N = int(input())
print(get(N))
