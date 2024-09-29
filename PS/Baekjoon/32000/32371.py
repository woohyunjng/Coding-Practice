arr = []

for i in range(4):
    arr.append(list(input()))

inp = set(list(input()))

go = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [-1, 1], [1, -1], [1, 1], [0, 0]]

for i in range(1, 3):
    for j in range(1, 9):
        res = set([])

        for x, y in go:
            res.add(arr[i + x][j + y])

        if res == inp:
            print(arr[i][j])
            exit()
