N, use = map(int, input().split())

arr = []
row, column = [0 for i in range(N)], [0 for i in range(N)]

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        line[j] = int(use == line[j])
        row[j] += line[j]
        column[i] += line[j]

    arr.append(line)

while True:
    yes, no = 0, 0

    for i in range(N):
        if (N + 1) // 2 <= row[i] < N:
            row[i] = N
            for j in range(N):
                if not arr[j][i]:
                    arr[j][i] = 1
                    column[j] += 1

    for i in range(N):
        if (N + 1) // 2 <= column[i]:
            if column[i] == N:
                yes += 1
                no += 1
                continue

            column[i] = N
            for j in range(N):
                if not arr[i][j]:
                    arr[i][j] = 1
                    row[j] += 1
        else:
            no += 1

    if yes == N:
        print(1)
        break
    elif no == N:
        print(0)
        break
