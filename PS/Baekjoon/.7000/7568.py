N = int(input())
arr = []

for i in range(N):
    x, y = map(int, input().split())
    arr.append([x, y])

for i in arr:
    rank = 1
    for j in arr:
        if j[0] > i[0] and j[1] > i[1]:
            rank += 1

    print(rank, end=" ")
