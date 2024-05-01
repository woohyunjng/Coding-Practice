from collections import deque

N, M = map(int, input().split())

arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))

day = 0
while True:
    check = True
    for i in range(N):
        for j in range(M):
            if arr[i][j]:
                check = False
                break
        if not check:
            break

    if check:
        break
    day += 1

    q = deque([(0, 0)])
    checked = [[False for j in range(M)] for i in range(N)]
    checked[0][0] = True
    meet = [[0 for j in range(M)] for i in range(N)]

    while len(q):
        i, j = q.popleft()
        go = [(i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)]

        for x, y in go:
            if x < 0 or x >= N or y < 0 or y >= M or checked[x][y]:
                continue

            if arr[x][y]:
                meet[x][y] += 1
                if meet[x][y] >= 2:
                    arr[x][y] = 0
                    checked[x][y] = True
            else:
                checked[x][y] = True
                q.append((x, y))

print(day)
