from itertools import combinations


def dis(a, b, c):
    a, b, c = set(a), set(b), set(c)
    return 12 - len(a & b) - len(b & c) - len(c & a)


T = int(input())
for i in range(T):
    N = int(input())
    S = input().split()

    if N >= 48:
        print(0)
    else:
        res = 100000000000
        for x, y, z in combinations(range(N), 3):
            res = min(res, dis(S[x], S[y], S[z]))
        print(res)
