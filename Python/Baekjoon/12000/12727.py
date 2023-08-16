T = int(input())
dp = [2, 6]

for i in range(T):
    N = int(input())

    if N >= len(dp):
        for j in range(len(dp), N + 1):
            dp.append(dp[-1] * 6 - dp[-2] * 4)

    print(f"Case #{i + 1}: {str((dp[N] - 1) % 1000).zfill(3)}")
