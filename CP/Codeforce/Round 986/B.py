from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, B, C = map(int, input().split())
    if B == 0:
        if C < N - 2:
            print(-1)
        elif C <= N - 1:
            print(N - 1)
        else:
            print(N)
        continue

    st, en = 0, N - 1
    res = 0

    while st <= en:
        md = st + en >> 1
        if B * md + C < N:
            st, res = md + 1, md + 1
        else:
            en = md - 1

    print(N - res)
