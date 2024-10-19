from sys import stdin

input = stdin.readline

N, Q = map(int, input().split())

L, R = 1, 2
res = 0

for q in range(Q):
    H, T = input().split()
    T = int(T)

    if H == "L":
        if L < R:
            if L <= T < R:
                res += T - L
            elif T < L:
                res += L - T
            else:
                res += L + N - T
        else:
            if R < T <= L:
                res += L - T
            elif T < R:
                res += T + N - L
            else:
                res += T - L
        L = T
    else:
        if L < R:
            if L < T <= R:
                res += R - T
            elif T < L:
                res += N + T - R
            else:
                res += T - R
        else:
            if R <= T < L:
                res += T - R
            elif T < R:
                res += R - T
            else:
                res += R + N - T
        R = T

print(res)
