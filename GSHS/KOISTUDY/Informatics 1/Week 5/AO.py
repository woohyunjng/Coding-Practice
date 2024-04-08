K = int(input())
C = int(input())

for i in range(C):
    M, N = map(int, input().split())
    res = 1

    if M > N:
        if (K - N) < 2 * (M - N) - 2:
            res = 0
    elif M < N:
        if (K - M) < 2 * (N - M) - 1:
            res = 0

    print(res)
