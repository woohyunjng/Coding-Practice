from collections import deque

M, N = map(int, input().split())
arr = []
good = deque([])

dp = [[-1 for j in range(M)] for i in range(N)]

for i in range(N):
    arr.append(list(map(int, input().split())))
    for j in range(M):
        if arr[i][j] == 1:
            good.append((i, j))
            dp[i][j] = 0

while len(good):
    i, j = good.popleft()
    go = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]

    for x, y in go:
        if x < 0 or x >= N or y < 0 or y >= M or arr[x][y] in [1, -1]:
            continue
        dp[x][y] = dp[i][j] + 1
        arr[x][y] = 1
        good.append((x, y))

res, check = -1, True
for i in range(N):
    for j in range(M):
        res = max(res, dp[i][j])
        if dp[i][j] == -1 and arr[i][j] != -1:
            check = False
            res = -1
            break
    if not check:
        break

print(res)
