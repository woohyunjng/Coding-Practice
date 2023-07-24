N = int(input())
dp = [[0, 0, 0]]
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

for i in range(N):
    dp.append(
        [
            min(dp[-1][1], dp[-1][2]) + arr[i][0],
            min(dp[-1][0], dp[-1][2]) + arr[i][1],
            min(dp[-1][0], dp[-1][1]) + arr[i][2],
        ]
    )

print(min(dp[N]))
