from collections import deque

N, M = map(int, input().split())
arr = [[]]
start = []

for i in range(1, N + 1):
    line = [0] + list(map(int, input().split()))
    arr.append(line)
    for j in range(1, M + 1):
        if line[j] == 2:
            start.append((i, j))
res = 0

for x1 in range(1, N + 1):
    for x2 in range(1, M + 1):
        if arr[x1][x2]:
            continue
        arr[x1][x2] = 1

        for y1 in range(1, N + 1):
            for y2 in range(1, M + 1):
                if arr[y1][y2]:
                    continue
                arr[y1][y2] = 1

                for z1 in range(1, N + 1):
                    for z2 in range(1, M + 1):
                        if arr[z1][z2]:
                            continue
                        arr[z1][z2] = 1

                        q = deque(start)
                        checked = [[False for j in range(M + 1)] for i in range(N + 1)]

                        while len(q):
                            i, j = q.popleft()
                            checked[i][j] = True
                            go = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]

                            for a, b in go:
                                if (
                                    a < 1
                                    or a > N
                                    or b < 1
                                    or b > M
                                    or checked[a][b]
                                    or arr[a][b]
                                ):
                                    continue
                                checked[a][b] = True
                                q.append((a, b))

                        res_i = 0
                        for a in range(1, N + 1):
                            for b in range(1, M + 1):
                                if not checked[a][b] and not arr[a][b]:
                                    res_i += 1
                        res = max(res, res_i)
                        arr[z1][z2] = 0
                arr[y1][y2] = 0
        arr[x1][x2] = 0

print(res)
