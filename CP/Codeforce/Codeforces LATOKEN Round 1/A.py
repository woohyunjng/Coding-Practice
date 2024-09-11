from sys import stdin
from collections import deque

input = stdin.readline
T = int(input())

for t in range(T):
    N, M = map(int, input().split())
    arr = []
    checked = [[False for _ in range(M)] for _ in range(N)]

    q = deque([])
    res = True

    for i in range(N):
        arr.append(list(map(lambda x: {".": 0, "R": 1, "W": 2}[x], input().rstrip())))
        for j in range(M):
            if arr[i][j] != 0:
                checked[i][j] = True
                q.append((i, j))

    if not len(q):
        checked[0][0] = True
        q.append((0, 0))
        arr[0][0] = 1

    while len(q):
        i, j = q.popleft()
        K = arr[i][j]
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ni, nj = i + dx, j + dy
            if ni < 0 or ni >= N or nj < 0 or nj >= M:
                continue
            if checked[ni][nj]:
                if arr[ni][nj] == arr[i][j]:
                    res = False
                    break
            else:
                arr[ni][nj] = 3 - arr[i][j]
                checked[ni][nj] = True
                q.append((ni, nj))

        if not res:
            break

    print("YES" if res else "NO")
    if not res:
        continue

    for i in range(N):
        print("".join(["R" if x == 1 else "W" for x in arr[i]]))
