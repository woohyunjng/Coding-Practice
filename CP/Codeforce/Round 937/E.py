# 100 (1:47 +1)


def comp(A, B):
    res = 0
    for i in range(len(A)):
        if A[i] != B[i]:
            res += 1
    return res


T = int(input())
for i in range(T):
    N = int(input())
    S = input()

    for j in range(1, N):
        if N % j:
            continue
        res1 = 0
        for i in range(1, N // j):
            res1 += comp(S[j * i : j * (i + 1)], S[:j])
        res2 = 0
        for i in range(N // j - 1):
            res2 += comp(S[j * i : j * (i + 1)], S[N - j : N])
        if min(res1, res2) <= 1:
            print(j)
            break
    else:
        print(N)
