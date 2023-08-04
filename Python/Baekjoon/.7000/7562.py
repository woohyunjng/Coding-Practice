from collections import deque

T = int(input())
for i in range(T):
    l = int(input())
    x_from, y_from = map(int, input().split())
    x_go, y_go = map(int, input().split())

    q = deque([(x_from, y_from, 0)])
    checked = [[False for k in range(l)] for j in range(l)]
    checked[x_from][y_from] = True

    while len(q):
        a, b, c = q.popleft()
        if (a, b) == (x_go, y_go):
            print(c)
            break

        go = [
            (a + 2, b + 1),
            (a + 2, b - 1),
            (a + 1, b + 2),
            (a + 1, b - 2),
            (a - 1, b + 2),
            (a - 1, b - 2),
            (a - 2, b - 1),
            (a - 2, b + 1),
        ]

        for x, y in go:
            if x >= l or x < 0 or y >= l or y < 0 or checked[x][y]:
                continue
            checked[x][y] = True
            q.append((x, y, c + 1))
