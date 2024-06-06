from sys import stdin


def get_res(S, N):
    res = [0 for i in range(N)]
    j = 0
    for i in range(1, N):
        while j > 0 and S[i] != S[j]:
            j = res[j - 1]
        if S[i] == S[j]:
            j += 1
        res[i] = j
    return res[-1]


T = int(stdin.readline())
for t in range(T):
    N, K = map(int, stdin.readline().rstrip().split())
    S = stdin.readline().rstrip()

    A, B = "", ""
    check = True
    for i in range(N // K):
        if check:
            A += "1" * K
            B += "0" * K
        else:
            A += "0" * K
            B += "1" * K
        check = not check

    A_res, B_res = get_res(A + "2" + S, 2 * N + 1), get_res(B + "2" + S, 2 * N + 1)
    res = -1

    if A_res >= B_res:
        S_res = S[-A_res:] + S[:-A_res][::-1]
        if S_res == A:
            res = N - A_res
    else:
        S_res = S[-B_res:] + S[:-B_res][::-1]
        if S_res == B:
            res = N - B_res

    print(res if res != 0 else N)
