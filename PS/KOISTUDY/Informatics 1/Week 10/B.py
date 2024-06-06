from sys import setrecursionlimit

setrecursionlimit(10**6)


def gcd(A, B):
    if A == 0:
        return B
    return gcd(B % A, A)


A, B = map(int, input().split())
print(gcd(A, B))
