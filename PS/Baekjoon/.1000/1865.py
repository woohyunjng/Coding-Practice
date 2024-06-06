T = int(input())
for i in range(T):
    N, M, W = map(int, input().split())
    arr = []

    for i in range(M):
        S, E, T = map(int, input().split())
        arr.append((S - 1, E - 1, T))
        arr.append((E - 1, S - 1, T))

    for i in range(W):
        S, E, T = map(int, input().split())
        arr.append((S - 1, E - 1, -T))

    dp = [1e15 for i in range(N)]
    dp[0] = 0
    cycle = False

    for i in range(N):
        for S, E, T in arr:
            if dp[E] > dp[S] + T:
                dp[E] = dp[S] + T
                if i == N - 1:
                    cycle = True

    print("YES" if cycle else "NO")
