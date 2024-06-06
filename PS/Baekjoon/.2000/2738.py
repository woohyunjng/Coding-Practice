N, M = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

for i in range(N):
    B = list(map(int, input().split()))
    for j in range(M):
        arr[i][j] += B[j]

for i in range(N):
    print(" ".join(map(str, arr[i])))
