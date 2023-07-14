N, M = map(int, input().split())
chess = ["WBWBWBWB", "BWBWBWBW"]

or1, or2 = [chess[i % 2] for i in range(8)], [chess[i % 2] for i in range(1, 9)]

arr = []
for i in range(N):
    arr.append(input())

mn = 1000000000000000000
for x in range(N - 7):
    for y in range(M - 7):
        sub1, sub2 = 0, 0
        for i in range(8):
            for j in range(8):
                if arr[i + x][j + y] != or1[i][j]:
                    sub1 += 1
                if arr[i + x][j + y] != or2[i][j]:
                    sub2 += 1
        mn = min(mn, min(sub1, sub2))

print(mn)
