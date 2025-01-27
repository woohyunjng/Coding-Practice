from collections import deque

N = int(input())
arr = []

shark_x, shark_y = 0, 0
shark_size = 2
need_fish = 2

res = 0

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        if line[j] == 9:
            shark_x, shark_y = i, j
            line[j] = 0
    arr.append(line)

while True:
    q = deque([(shark_x, shark_y, 0)])
    checked = [[False for j in range(N)] for i in range(N)]
    checked[shark_x][shark_y] = True

    allow = []

    while len(q):
        i, j, k = q.popleft()
        if 1 <= arr[i][j] < shark_size:
            allow.append((i, j, k))

        go = [(i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)]

        for x, y in go:
            if (
                x >= N
                or x < 0
                or y >= N
                or y < 0
                or checked[x][y]
                or arr[x][y] > shark_size
            ):
                continue
            checked[x][y] = True
            q.append((x, y, k + 1))

    if not len(allow):
        break

    i, j, k = min(allow, key=lambda x: 10000 * x[2] + 100 * x[0] + x[1])
    arr[i][j] = 0
    res += k
    need_fish -= 1

    shark_x, shark_y = i, j

    if not need_fish:
        shark_size += 1
        need_fish = shark_size

print(res)
