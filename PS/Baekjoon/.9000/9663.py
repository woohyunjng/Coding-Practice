N = int(input())
arr = [[False for j in range(N)] for i in range(N)]


def dfs(line):
    if line == N:
        return 1

    res = 0
    for i in range(N):
        if arr[line][i]:
            continue

        checked = []
        for j in range(line, N):
            if not arr[j][i]:
                checked.append((j, i))
            if i + j - line < N and not arr[j][i + j - line]:
                checked.append((j, i + j - line))
            if i - j + line >= 0 and not arr[j][i - j + line]:
                checked.append((j, i - j + line))

        for j, k in checked:
            arr[j][k] = True

        res += dfs(line + 1)

        for j, k in checked:
            arr[j][k] = False

    return res


print(dfs(0))
