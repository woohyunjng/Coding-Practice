N = int(input())
work = [[0, 0]]

for _ in range(N):
    work.append(list(map(int, input().split())))

dp = [0 for _ in range(N + 2)]
mx = 0

for i in range(1, N + 1):
    mx = max(mx, dp[i])
    if i + work[i][0] - 1 > N:
        continue

    dp[i + work[i][0]] = max(mx + work[i][1], dp[i + work[i][0]])

print(max(dp))
