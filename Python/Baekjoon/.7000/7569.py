from collections import deque

M, N, H = map(int, input().split())
arr = []
good = deque([])

dp = [[[-1 for k in range(M)] for j in range(N)] for i in range(H)]

for i in range(H):
    arr.append([])
    for j in range(N):
        arr[i].append(list(map(int, input().split())))
        for k in range(M):
            if arr[i][j][k] == 1:
                good.append((i, j, k))
                dp[i][j][k] = 0

while len(good):
    i, j, k = good.popleft()
    go = [
        (i + 1, j, k),
        (i - 1, j, k),
        (i, j + 1, k),
        (i, j - 1, k),
        (i, j, k + 1),
        (i, j, k - 1),
    ]

    for x, y, z in go:
        if (
            x < 0
            or x >= H
            or y < 0
            or y >= N
            or z < 0
            or z >= M
            or arr[x][y][z] in [1, -1]
        ):
            continue

        dp[x][y][z] = dp[i][j][k] + 1
        arr[x][y][z] = 1
        good.append((x, y, z))

res, check = -1, True
for i in range(H):
    for j in range(N):
        for k in range(M):
            res = max(res, dp[i][j][k])
            if dp[i][j][k] == -1 and arr[i][j][k] != -1:
                check = False
                res = -1
                break

        if not check:
            break
    if not check:
        break

print(res)
