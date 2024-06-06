# 100 -> 0 (Hacked)

from collections import defaultdict

T = int(input())
for t in range(T):
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    left = defaultdict(int)
    base = defaultdict(int)
    pr = defaultdict(int)
    for i in B:
        left[i] += 1
        base[i] += 1

    res = 0
    cur = 0
    for i in range(M):
        if base[A[i]] and left[A[i]]:
            left[A[i]] -= 1
            cur += 1
        pr[A[i]] += 1

    if cur >= K:
        res += 1

    for i in range(M, N):
        pr[A[i - M]] -= 1
        pr[A[i]] += 1

        if pr[A[i - M]] < base[A[i - M]]:
            left[A[i - M]] += 1
            cur -= 1

        if base[A[i]] and left[A[i]]:
            left[A[i]] -= 1
            cur += 1

        if cur >= K:
            res += 1

    print(res)
