from math import sqrt, log, sin

N = 1000000
MOD = 1000000

dp = [0] * (N + 1)
dp[0] = 1

for i in range(1, N + 1):
    dp[i] = (
        dp[int(i - sqrt(i))] + dp[int(log(i))] + dp[int(i * sin(i) * sin(i))]
    ) % MOD

while True:
    X = int(input())
    if X == -1:
        break
    print(dp[X])
