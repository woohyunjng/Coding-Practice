dp = [1, 1]

T = int(input())
for i in range(T):
    N = int(input())
    if N >= len(dp):
        while N >= len(dp):
            dp.append(dp[-1] + dp[-2])
    print(dp[N])
