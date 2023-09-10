R, C, H = map(int, input().split())
arr = []

res = [[[0 for k in range(C)] for j in range(R)] for i in range(H)]

for i in range(H):
    arr.append([])
    for j in range(R):
        arr[-1].append(list(input()))

for i in range(H):
    for j in range(R):
        for k in range(C):
            if arr[i][j][k] == "*":
                res[i][j][k] = "*"
                continue

            search = [
                (i + 1, j + 1, k + 1),
                (i + 1, j + 1, k - 1),
                (i + 1, j + 1, k),
                (i + 1, j - 1, k + 1),
                (i + 1, j - 1, k - 1),
                (i + 1, j - 1, k),
                (i + 1, j, k + 1),
                (i + 1, j, k - 1),
                (i + 1, j, k),
                (i - 1, j + 1, k + 1),
                (i - 1, j + 1, k - 1),
                (i - 1, j + 1, k),
                (i - 1, j - 1, k + 1),
                (i - 1, j - 1, k - 1),
                (i - 1, j - 1, k),
                (i - 1, j, k + 1),
                (i - 1, j, k - 1),
                (i - 1, j, k),
                (i, j + 1, k + 1),
                (i, j + 1, k - 1),
                (i, j + 1, k),
                (i, j - 1, k + 1),
                (i, j - 1, k - 1),
                (i, j - 1, k),
                (i, j, k + 1),
                (i, j, k - 1),
            ]

            for x, y, z in search:
                if x >= H or x < 0 or y >= R or y < 0 or z >= C or z < 0:
                    continue

                if arr[x][y][z] == "*":
                    res[i][j][k] += 1
            res[i][j][k] %= 10

for i in range(H):
    for j in range(R):
        print("".join(map(str, res[i][j])))
