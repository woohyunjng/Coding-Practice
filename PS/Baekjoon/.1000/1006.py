from sys import stdin


def solve(N, W, arr, dp):
    for i in range(1, N + 1):
        p = [
            1 if arr[i][0] + arr[i][1] <= W else 2,
            1 if arr[i][0] + arr[i - 1][0] <= W else 2,
            1 if arr[i][1] + arr[i - 1][1] <= W else 2,
        ]

        dp[i] = [
            min(
                dp[i - 2][0] + p[1] + p[2],
                dp[i - 1][0] + p[0],
                dp[i - 1][1] + p[2] + 1,
                dp[i - 1][2] + p[1] + 1,
            ),
            min(dp[i - 1][0] + 1, dp[i - 1][2] + p[1]),
            min(dp[i - 1][0] + 1, dp[i - 1][1] + p[2]),
        ]


T = int(stdin.readline())
for i in range(T):
    N, W = map(int, stdin.readline().rstrip().split())
    arr = [[0, 0] for i in range(N + 1)]

    up = list(map(int, stdin.readline().rstrip().split()))
    down = list(map(int, stdin.readline().rstrip().split()))
    for i in range(1, N + 1):
        arr[i] = [up[i - 1], down[i - 1]]

    dp = [[0, 0, 0] for i in range(N + 1)]
    if arr[1][0] + arr[1][1] <= W:
        dp[1] = [1, 1, 1]
    else:
        dp[1] = [2, 1, 1]

    solve(N, W, arr, dp)
    res = dp[N][0]

    if arr[1][0] + arr[N][0] <= W and arr[1][1] + arr[N][1] <= W:
        dp[1] = [2, 1, 1]
        solve(N, W, [[0, 0], [1e9, 1e9]] + arr[2:], dp)
        res = min(res, dp[N - 1][0])

    if arr[1][0] + arr[N][0] <= W:
        dp[1] = [2, 1, 1]
        solve(N, W, [[0, 0], [1e9, arr[1][1]]] + arr[2:], dp)
        res = min(res, dp[N][2])

    if arr[1][1] + arr[N][1] <= W:
        dp[1] = [2, 1, 1]
        solve(N, W, [[0, 0], [arr[1][0], 1e9]] + arr[2:], dp)
        res = min(res, dp[N][1])

    if N == 1:
        if arr[1][0] + arr[1][1] <= W:
            res = 1
        else:
            res = 2

    print(res)
