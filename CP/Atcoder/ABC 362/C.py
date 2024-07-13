from sys import stdin

input = stdin.readline

N = int(input())
arr = []

sumL, sumR = 0, 0

for i in range(N):
    arr.append(list(map(int, input().rstrip().split())))
    sumL += arr[-1][0]
    sumR += arr[-1][1]

if sumL <= 0 <= sumR:
    X = [i[0] for i in arr]
    rest = -sumL

    for i in range(N):
        if not rest:
            break
        if arr[i][1] - arr[i][0] > rest:
            X[i] += rest
            rest = 0
        else:
            rest -= arr[i][1] - arr[i][0]
            X[i] = arr[i][1]
    print("Yes")
    print(*X)
else:
    print("No")
