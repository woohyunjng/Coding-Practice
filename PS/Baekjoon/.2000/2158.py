import heapq
import math

V, R, C = map(int, input().split())

arr = [[0 for j in range(C + 1)] for i in range(R + 1)]
dp = [[float("inf") for j in range(C + 1)] for i in range(R + 1)]
vel = [[0 for j in range(C + 1)] for i in range(R + 1)]

for i in range(1, R + 1):
    row = list(map(int, input().split()))
    for j in range(1, C + 1):
        arr[i][j] = row[j - 1]
        vel[i][j] = 1 << (arr[i][j] - arr[1][1] + 50)

pq = []
heapq.heappush(pq, (0, 1, 1))
dp[1][1] = 0

while pq:
    cur_time, x, y = heapq.heappop(pq)
    if dp[x][y] != cur_time:
        continue

    for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        nx, ny = x + dx, y + dy
        if nx < 1 or nx > R or ny < 1 or ny > C:
            continue

        new_time = dp[x][y] + vel[x][y]
        if dp[nx][ny] > new_time:
            dp[nx][ny] = new_time
            heapq.heappush(pq, (new_time, nx, ny))

res = dp[R][C] / V / (2**50)
print(f"{res:.2f}")
