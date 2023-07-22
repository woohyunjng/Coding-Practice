N, M = map(int, input().split())
arr = [i for i in range(N + 1)]

for a in range(M):
    i, j = map(int, input().split())
    arr[i], arr[j] = arr[j], arr[i]

print(" ".join(map(str, arr[1:])))
