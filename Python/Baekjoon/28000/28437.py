N = int(input())
A = list(map(int, input().split()))

Q = int(input())
L = list(map(int, input().split()))

dp = [0 for i in range(100001)]
for i in A:
    dp[i] += 1

for i in range(1, 100001):
    if not dp[i]:
        continue

    for j in range(i * 2, 100001, i):
        dp[j] += dp[i]

for i in L:
    print(dp[i], end=" ")
