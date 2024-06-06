N, M = map(int, input().split())
arr = [0 for i in range(N + 1)]

for a in range(M):
    i, j, k = map(int, input().split())
    for b in range(i, j + 1):
        arr[b] = k

print(" ".join(map(str, arr[1:])))
