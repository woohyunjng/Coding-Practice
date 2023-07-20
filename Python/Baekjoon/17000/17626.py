n = int(input())
dp = [0]

for i in range(1, n + 1):
    dp.append(10000000000000000000000)
    j = 1

    while j ** 2 <= i:
        dp[i] = min(dp[i], dp[i - j ** 2] + 1)
        j += 1

print(dp[-1])
