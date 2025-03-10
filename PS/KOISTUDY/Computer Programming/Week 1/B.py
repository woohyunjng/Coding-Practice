N = int(input())

res = [["." for i in range(N)] for i in range(N)]
res[0] = res[N - 1] = ["Z" for i in range(N)]

for i in range(1, N - 1):
    res[i][N - 1 - i] = "Z"

for i in res:
    print("".join(i))
