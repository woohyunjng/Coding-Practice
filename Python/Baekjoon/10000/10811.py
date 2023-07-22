N, M = map(int, input().split())
arr = [i for i in range(N + 1)]

for a in range(M):
    i, j = map(int, input().split())
    arr[i : j + 1] = list(reversed(arr[i : j + 1]))

print(" ".join(map(str, arr[1:])))
