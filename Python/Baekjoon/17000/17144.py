R, C, T = map(int, input().split())
x = -1
arr = []

for i in range(R):
    line = list(map(int, input().split()))
    arr.append(line)
    for j in line:
        if j == -1 and x == -1:
            x = i

for i in range(T):
    use = [[0 for j in range(C)] for i in range(R)]
    for j in range(R):
        for k in range(C):
            go = [(j - 1, k), (j + 1, k), (j, k + 1), (j, k - 1)]
            if arr[j][k] <= 0:
                continue

            for y, z in go:
                if y < 0 or y >= R or z < 0 or z >= C or arr[y][z] == -1:
                    continue

                use[y][z] += arr[j][k] // 5
                use[j][k] -= arr[j][k] // 5

    for j in range(R):
        for k in range(C):
            arr[j][k] += use[j][k]

    arr[x - 1][0] = 0
    for j in range(x - 2, -1, -1):
        arr[j + 1][0], arr[j][0] = arr[j][0], 0

    for j in range(1, C):
        arr[0][j - 1], arr[0][j] = arr[0][j], 0

    for j in range(1, x + 1):
        arr[j][C - 1], arr[j - 1][C - 1] = 0, arr[j][C - 1]

    for j in range(C - 2, 0, -1):
        arr[x][j + 1], arr[x][j] = arr[x][j], 0

    arr[x + 2][0] = 0
    for j in range(x + 3, R):
        arr[j - 1][0], arr[j][0] = arr[j][0], 0

    for j in range(1, C):
        arr[R - 1][j - 1], arr[R - 1][j] = arr[R - 1][j], 0

    for j in range(R - 2, x, -1):
        arr[j][C - 1], arr[j + 1][C - 1] = 0, arr[j][C - 1]

    for j in range(C - 2, 0, -1):
        arr[x + 1][j + 1], arr[x + 1][j] = arr[x + 1][j], 0

res = 0
for i in range(R):
    for j in range(C):
        if arr[i][j] > 0:
            res += arr[i][j]
print(res)
