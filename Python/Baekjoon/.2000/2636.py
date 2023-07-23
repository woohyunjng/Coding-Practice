from collections import deque
from copy import deepcopy

N, M = map(int, input().split())

arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))

arr_day = [deepcopy(arr)]

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

    while len(q):
        i, j = q.popleft()
        go = [(i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)]

        for x, y in go:
            if x < 0 or x >= N or y < 0 or y >= M or checked[x][y]:
                continue
            checked[x][y] = True
            if arr[x][y]:
                arr[x][y] = 0
            else:
                q.append((x, y))
    
    arr_day.append(deepcopy(arr))

res = 0
for i in range(N):
    for j in range(M):
        res += arr_day[day - 1][i][j]

print(day)
print(res)
