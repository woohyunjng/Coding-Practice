from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().split())
    res = []

    arr = []
    for i in range(N):
        arr.append(list(map(int, input().rstrip())))

    for i in range(0, N, K):
        res.append([])
        for j in range(0, N, K):
            res[-1].append(arr[i][j])

    for i in res:
        print(*i, sep="")
