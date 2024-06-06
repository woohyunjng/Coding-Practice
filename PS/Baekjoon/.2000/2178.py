from collections import deque

N, M = map(int, input().split())
checked = [[False for j in range(M)] for i in range(N)]
arr = []

for i in range(N):
    arr.append(list(map(int, input())))

q = deque([(0, 0)])
dp = [[0 for j in range(M)] for i in range(N)]
dp[0][0] = 1

while len(q):
    i, j = q.popleft()
    go = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]

    for x, y in go:
        if x >= M or x < 0:
            continue
        if y >= N or y < 0:
            continue
        if not arr[y][x]:
            continue

        if not checked[y][x]:
            checked[y][x] = True
            dp[y][x] = dp[j][i] + 1
            q.append((x, y))

print(dp[N - 1][M - 1])
