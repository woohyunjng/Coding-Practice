from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, X = map(int, input().split())
    res = 0

    for a in range(1, int(N**0.5) + 1):
        for b in range(a + 1, int(N**0.5) + 1):
            S = b + 1
            E = min(X - a - b, (N - a * b) // (a + b))
            res += max(0, E - S + 1) * 6

    res += min(X // 3, int((N // 3) ** 0.5))

    for a in range(1, int(N**0.5) + 1):
        S = a + 1
        E = min(X - 2 * a, (N - a**2) // (2 * a))
        res += max(0, E - S + 1) * 3

    for a in range(1, int(N**0.5) + 1):
        S = a + 1
        E = min((X - a) // 2, int((N + a**2) ** 0.5) - a)
        res += max(0, E - S + 1) * 3

    print(res)
