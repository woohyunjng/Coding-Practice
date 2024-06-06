from collections import deque

N, M = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(input()))
    for j in range(M):
        if arr[i][j] == "I":
            st_i, st_j = i, j

checked = [[False for j in range(M)] for i in range(N)]
q = deque([(st_i, st_j)])

res = 0

while len(q):
    i, j = q.popleft()
    go = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]

    for x, y in go:
        if x < 0 or x >= N or y < 0 or y >= M or checked[x][y] or arr[x][y] == "X":
            continue
        checked[x][y] = True

        if arr[x][y] == "P":
            res += 1
        q.append((x, y))

print(res if res else "TT")
