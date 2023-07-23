N, M = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

mx = -1

for i in range(N):
    for j in range(M - 3):
        mx = max(mx, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3])

for i in range(N - 3):
    for j in range(M):
        mx = max(mx, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j])

for i in range(N - 1):
    for j in range(M - 1):
        mx = max(mx, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1])

for i in range(N - 1):
    for j in range(M - 2):
        sm = sum(arr[i][j : j + 3]) + sum(arr[i + 1][j : j + 3])
        mx = max(mx, sm - arr[i][j] - arr[i][j + 1])
        mx = max(mx, sm - arr[i][j] - arr[i + 1][j + 2])
        mx = max(mx, sm - arr[i][j] - arr[i][j + 2])
        mx = max(mx, sm - arr[i + 1][j] - arr[i + 1][j + 1])
        mx = max(mx, sm - arr[i + 1][j] - arr[i + 1][j + 2])
        mx = max(mx, sm - arr[i + 1][j] - arr[i][j + 2])
        mx = max(mx, sm - arr[i][j + 1] - arr[i][j + 2])
        mx = max(mx, sm - arr[i + 1][j + 1] - arr[i + 1][j + 2])

for i in range(N - 2):
    for j in range(M - 1):
        sm = (
            sum(arr[i][j : j + 2])
            + sum(arr[i + 1][j : j + 2])
            + sum(arr[i + 2][j : j + 2])
        )
        mx = max(mx, sm - arr[i][j] - arr[i + 1][j])
        mx = max(mx, sm - arr[i][j] - arr[i + 2][j + 1])
        mx = max(mx, sm - arr[i][j] - arr[i + 2][j])
        mx = max(mx, sm - arr[i][j + 1] - arr[i + 1][j + 1])
        mx = max(mx, sm - arr[i][j + 1] - arr[i + 2][j + 1])
        mx = max(mx, sm - arr[i][j + 1] - arr[i + 2][j])
        mx = max(mx, sm - arr[i + 1][j] - arr[i + 2][j])
        mx = max(mx, sm - arr[i + 1][j + 1] - arr[i + 2][j + 1])

print(mx)
