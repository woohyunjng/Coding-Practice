from sys import stdin

T = int(stdin.readline())

for i in range(T):
    N = int(stdin.readline())
    A, B, C, D, E = N // 60, 0, 0, 0, 0

    rev = False

    N %= 60
    if N >= 36:
        N = 60 - N
        A += 1
        rev = True

    if not rev:
        B = N // 10
    else:
        C = N // 10
    N %= 10

    if not rev:
        if N >= 6:
            B += 1
            E = 10 - N
        elif N:
            D = N
    else:
        if N >= 6:
            C += 1
            D = 10 - N
        elif N:
            E = N

    print(A, B, C, D, E)
