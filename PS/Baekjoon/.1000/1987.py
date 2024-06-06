from collections import deque

R, C = map(int, input().split())
arr, res = [], 1

for i in range(R):
    arr.append(list(map(lambda x: ord(x) - 65, input())))


def dfs(i, j, visited, k):
    global res
    res = max(res, k)

    visited[arr[i][j]] = True
    go = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]

    for x, y in go:
        if x < 0 or x >= R or y < 0 or y >= C or visited[arr[x][y]]:
            continue

        dfs(x, y, visited, k + 1)

        visited[arr[x][y]] = False


dfs(0, 0, [False for i in range(26)], 1)
print(res)
