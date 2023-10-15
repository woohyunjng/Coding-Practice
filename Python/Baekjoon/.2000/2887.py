from sys import stdin

N = int(stdin.readline())
arr = []

for i in range(N):
    arr.append([i] + list(map(int, stdin.readline().rstrip().split())))

lines = []

arr = list(sorted(arr, key=lambda x: x[1]))
for i in range(N - 1):
    lines.append(
        (
            abs(arr[i][1] - arr[i + 1][1]),
            arr[i][0],
            arr[i + 1][0],
        )
    )

arr = list(sorted(arr, key=lambda x: x[2]))
for i in range(N - 1):
    lines.append(
        (
            abs(arr[i][2] - arr[i + 1][2]),
            arr[i][0],
            arr[i + 1][0],
        )
    )

arr = list(sorted(arr, key=lambda x: x[3]))
for i in range(N - 1):
    lines.append(
        (
            abs(arr[i][3] - arr[i + 1][3]),
            arr[i][0],
            arr[i + 1][0],
        )
    )

lines = list(sorted(lines))
parent = [i for i in range(N)]


def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])
    return parent[i]


def uni(i, j):
    i, j = find(i), find(j)
    parent[max(i, j)] = min(i, j)


res = 0
for i, j, k in lines:
    j, k = find(j), find(k)
    if j != k:
        uni(j, k)
        res += i

print(res)
