N = int(input())
M = int(input())

arr = []
for i in range(M):
    arr.append(list(map(int, input().split())))

arr = list(sorted(arr, key=lambda x: x[1]))

dp = [[N, 0, 0] for j in range(N + 2)]
for i in range(M):
    if not i:
        for j in range(arr[i][1] + 1, N + 2):
            dp[j] = [
                max(N - arr[i][1], arr[i][0] - 1),
                max(arr[i][0] - 1, j - arr[i][1] - 1),
                arr[i][1],
            ]
        continue

    for j in range(arr[i][1] + 1, N + 2):
        ns = max(dp[arr[i][0]][1], arr[i][0] - dp[arr[i][0]][2] - 1, j - arr[i][1] - 1)

        if ns <= dp[j][1]:
            dp[j] = [
                max(ns, N - arr[i][1]),
                ns,
                arr[i][1],
            ]

print(min([dp[i][0] for i in range(N + 2)]))
