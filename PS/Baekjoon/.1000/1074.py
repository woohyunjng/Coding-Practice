N, r, c = map(int, input().split())


def find(x, y, M):
    if M == 0:
        return 0

    res = 0
    if x >= 2 ** (M - 1):
        res += 2 ** (2 * M - 2)
        x -= 2 ** (M - 1)
    if y >= 2 ** (M - 1):
        res += 2 ** (2 * M - 1)
        y -= 2 ** (M - 1)

    return res + find(x, y, M - 1)


print(find(c, r, N))
