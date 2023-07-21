from collections import deque

n, m = map(int, input().split())
arr, start = [], -1

for i in range(n):
    arr2 = list(map(int, input().split()))
    for j in range(m):
        if arr2[j] == 2:
            start = (i, j)
    arr.append(arr2)

checked = [[False for j in range(m)] for i in range(n)]
dp = [[0 for j in range(m)] for i in range(n)]
q = deque([start])

checked[start[0]][start[1]] = True

while len(q):
    i, j = q.popleft()
    go = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]

    for x, y in go:
        if x >= n or x < 0 or y >= m or y < 0:
            continue
        if not arr[x][y]:
            continue

        if not checked[x][y]:
            checked[x][y] = True
            dp[x][y] = dp[i][j] + 1
            q.append((x, y))

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and not dp[i][j]:
            print(-1, end=" ")
        else:
            print(dp[i][j], end=" ")
    print("\n", end="")
