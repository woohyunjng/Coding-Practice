N = int(input())
stairs = [0, 0, 0]
dp = [0, 0, 0]

for _ in range(N):
    stairs.append(int(input()))

for i in range(3, N + 3):
    dp.append(max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i])

print(dp[-1])
