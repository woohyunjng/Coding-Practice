from sys import stdin
from collections import defaultdict

T = int(stdin.readline())
for t in range(T):
    N = int(stdin.readline())
    A = list(map(int, stdin.readline().rstrip().split()))
    B = list(map(int, stdin.readline().rstrip().split()))
    M = int(stdin.readline())
    D = list(map(int, stdin.readline().rstrip().split()))

    dct = defaultdict(int)
    for i in D:
        dct[i] += 1

    res = True
    for i in range(N):
        if A[i] == B[i]:
            continue

        if not dct[B[i]]:
            res = False
            break
        dct[B[i]] -= 1

    if D[-1] not in B:
        res = False
    print("YES" if res else "NO")
