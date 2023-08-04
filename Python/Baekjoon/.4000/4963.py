from collections import deque

while True:
    w, h = map(int, input().split())
    if not (w + h):
        break

    arr = []
    for i in range(h):
        arr.append(list(map(int, input().split())))

    checked = [[False for j in range(w)] for i in range(h)]
    res = 0

    for i in range(h):
        for j in range(w):
            if checked[i][j] or not arr[i][j]:
                continue

            res += 1

            q = deque([(i, j)])
            checked[i][j] = True

            while len(q):
                x, y = q.popleft()
                go = [
                    (x + 1, y),
                    (x - 1, y),
                    (x, y + 1),
                    (x, y - 1),
                    (x + 1, y + 1),
                    (x + 1, y - 1),
                    (x - 1, y + 1),
                    (x - 1, y - 1),
                ]
                for m, n in go:
                    if (
                        m >= h
                        or m < 0
                        or n >= w
                        or n < 0
                        or not arr[m][n]
                        or checked[m][n]
                    ):
                        continue
                    checked[m][n] = True
                    q.append((m, n))

    print(res)
