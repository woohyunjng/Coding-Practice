N = int(input())
arr, visited = [], []

for _ in range(N):
    arr.append(list(map(int, list(input()))))
    visited.append([False for _2 in range(N)])


def get_next(i, j):
    next_arr = []
    if i != 0:
        next_arr.append((i - 1, j))
    if j != 0:
        next_arr.append((i, j - 1))
    if i != N - 1:
        next_arr.append((i + 1, j))
    if j != N - 1:
        next_arr.append((i, j + 1))
    return next_arr


def dfs(i, j):
    if visited[i][j] or not arr[i][j]:
        return 0

    res_val = 1
    visited[i][j] = True

    for i2, j2 in get_next(i, j):
        res_val += dfs(i2, j2)

    return res_val


res = []
for i in range(N):
    for j in range(N):
        val = dfs(i, j)
        if val:
            res.append(val)

print(len(res))
print("\n".join(map(str, sorted(res))))
