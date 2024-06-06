arr = []
for i in range(9):
    arr.append(list(map(int, input())))

checked_x, checked_y, checked_block = (
    [[False for j in range(10)] for i in range(9)],
    [[False for j in range(10)] for i in range(9)],
    [[[False for k in range(10)] for j in range(3)] for i in range(3)],
)
for i in range(9):
    for j in range(9):
        checked_x[j][arr[i][j]] = True
        checked_y[i][arr[i][j]] = True
        checked_block[i // 3][j // 3][arr[i][j]] = True


def get_next(x, y):
    if x == 8:
        x = 0
        y += 1
    else:
        x += 1
    return (x, y)


def solve(x, y):
    if y >= 9:
        for i in arr:
            print("".join(map(str, i)))
        return True

    if arr[y][x] != 0:
        return solve(*get_next(x, y))

    for i in range(1, 10):
        if checked_x[x][i] or checked_y[y][i] or checked_block[y // 3][x // 3][i]:
            continue

        arr[y][x] = i
        checked_x[x][i] = True
        checked_y[y][i] = True
        checked_block[y // 3][x // 3][i] = True

        ret = solve(*get_next(x, y))
        if ret:
            return True

        arr[y][x] = 0
        checked_x[x][i] = False
        checked_y[y][i] = False
        checked_block[y // 3][x // 3][i] = False

    return False


solve(0, 0)
