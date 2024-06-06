from collections import deque

N, M = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(map(int, input())))

q = deque([(0, 0, False)])
dp = [[[-1, -1] for j in range(M)] for i in range(N)]

dp[0][0] = [1, -1]

while len(q):
    a, b, c = q.popleft()
    go = [(a + 1, b), (a - 1, b), (a, b + 1), (a, b - 1)]

    for x, y in go:
        if x >= N or x < 0 or y >= M or y < 0:
            continue

        if arr[x][y]:
            if not c:
                q.append((x, y, True))
                dp[x][y][1] = (
                    min(dp[a][b][0] + 1, dp[x][y][1])
                    if dp[x][y][1] >= 1
                    else dp[a][b][0] + 1
                )
        elif dp[x][y][int(c)] == -1:
            q.append((x, y, c))
            dp[x][y][int(c)] = dp[a][b][int(c)] + 1

print(min(dp[N - 1][M - 1]) if -1 not in dp[N - 1][M - 1] else max(dp[N - 1][M - 1]))
