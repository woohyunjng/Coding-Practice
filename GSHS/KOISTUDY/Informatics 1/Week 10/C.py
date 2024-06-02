from sys import setrecursionlimit

setrecursionlimit(10**6)


def get(K):
    if K == 1:
        return "*"
    return "\n".join([get(K - 1), "".join(["*"] * K)])


N = int(input())
print(get(N))
