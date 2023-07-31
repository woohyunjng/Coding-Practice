N, x, y = map(int, input().split())
s = y - x - 1

checked = [False for i in range(2 * N)]
checked[x - 1] = True
checked[y - 1] = True


def get(num):
    if num == N + 1:
        return 1

    if num == s:
        return get(num + 1)

    res = 0
    for i in range(2 * N - 1 - num):
        if not checked[i] and not checked[i + num + 1]:
            checked[i], checked[i + num + 1] = True, True
            res += get(num + 1)
            checked[i], checked[i + num + 1] = False, False

    return res


print(get(1))
