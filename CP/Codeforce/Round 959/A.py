from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, M = map(int, input().rstrip().split())
    arr = []

    for i in range(N):
        arr.append(list(map(int, input().rstrip().split())))

    if N == 1 and M == 1:
        print(-1)
    elif M == 1:
        arr_copy = []
        for i in range(N):
            arr_copy.append(arr[i][0])
        arr = arr_copy[1:] + [arr_copy[0]]
        print(*arr, sep="\n")
    else:
        for i in range(N):
            arr[i] = arr[i][1:] + [arr[i][0]]
            print(*arr[i], sep=" ")
