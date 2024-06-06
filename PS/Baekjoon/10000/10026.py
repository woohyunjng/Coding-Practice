from collections import deque

N = int(input())
arr, arr2 = [], []

for i in range(N):
    arr.append(list(map(lambda x: {"B": 1, "G": 2, "R": 3}[x], input())))
    arr2.append(list(map(lambda x: {1: 1, 2: 2, 3: 2}[x], arr[-1])))


def get(A):
    checked = [[False for j in range(N)] for i in range(N)]
    res = 0

    for i in range(N):
        for j in range(N):
            if not checked[i][j]:
                checked[i][j] = True
                q = deque([(i, j)])

                while len(q):
                    b, c = q.pop()
                    go = [(b + 1, c), (b, c + 1), (b - 1, c), (b, c - 1)]

                    for x, y in go:
                        if x >= N or x < 0 or y >= N or y < 0:
                            continue
                        if checked[x][y] or A[x][y] != A[b][c]:
                            continue

                        checked[x][y] = True
                        q.append((x, y))
                res += 1

    return res


print(get(arr), get(arr2))
