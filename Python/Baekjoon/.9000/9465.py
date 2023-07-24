T = int(input())
for i in range(T):
    N = int(input())
    S1 = list(map(int, input().split()))
    S2 = list(map(int, input().split()))
    dp = [[S1[0], S2[0], 0]]

    if N >= 2:
        dp.append([S1[1] + S2[0], S2[1] + S1[0], max(S1[0], S2[0])])
    for i in range(2, N):
        dp.append(
            [
                S1[i] + max(*dp[i - 2], *dp[i - 1][1:]),
                S2[i] + max(*dp[i - 2], dp[i - 1][0], dp[i - 1][2]),
                max(dp[i - 1]),
            ]
        )

    print(max(dp[N - 1]))
