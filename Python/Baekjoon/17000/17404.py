N = int(input())
arr, dp = [[0, 0, 0]], [[[0, 0, 0]], [[0, 0, 0]], [[0, 0, 0]]]

for i in range(N):
    arr.append(list(map(int, input().split())))

dp.append([[arr[1][0], 1e9, 1e9], [1e9, arr[1][1], 1e9], [1e9, 1e9, arr[1][2]]])
for i in range(2, N):
    dp.append(
        [
            [
                min(dp[-1][0][1], dp[-1][0][2]) + arr[i][0],
                min(dp[-1][0][0], dp[-1][0][2]) + arr[i][1],
                min(dp[-1][0][0], dp[-1][0][1]) + arr[i][2],
            ],
            [
                min(dp[-1][1][1], dp[-1][1][2]) + arr[i][0],
                min(dp[-1][1][0], dp[-1][1][2]) + arr[i][1],
                min(dp[-1][1][0], dp[-1][1][1]) + arr[i][2],
            ],
            [
                min(dp[-1][2][1], dp[-1][2][2]) + arr[i][0],
                min(dp[-1][2][0], dp[-1][2][2]) + arr[i][1],
                min(dp[-1][2][0], dp[-1][2][1]) + arr[i][2],
            ],
        ]
    )

print(
    min(
        arr[N][0] + min(dp[-1][1][1], dp[-1][1][2], dp[-1][2][1], dp[-1][2][2]),
        arr[N][1] + min(dp[-1][0][0], dp[-1][0][2], dp[-1][2][0], dp[-1][2][2]),
        arr[N][2] + min(dp[-1][0][0], dp[-1][0][1], dp[-1][1][0], dp[-1][1][1]),
    )
)
