from sys import setrecursionlimit

setrecursionlimit(10**5)


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = (arr[start], start)
    else:
        init(tree, arr, node * 2, start, (start + end) >> 1)
        init(tree, arr, node * 2 + 1, ((start + end) >> 1) + 1, end)

        if tree[node * 2][0] <= tree[node * 2 + 1][0]:
            tree[node] = tree[node * 2]
        else:
            tree[node] = tree[node * 2 + 1]


def query(tree, node, start, end, left, right):
    if left <= start and end <= right:
        return tree[node]
    elif right < start or end < left:
        return (1e9, -1)
    else:
        left_min = query(tree, node * 2, start, (start + end) >> 1, left, right)
        right_min = query(
            tree, node * 2 + 1, ((start + end) >> 1) + 1, end, left, right
        )
        if left_min[0] < right_min[0]:
            return left_min
        else:
            return right_min


def get_max(tree, N, left, right):
    if left == right:
        return query(tree, 1, 0, N - 1, left, right)[0]
    if left > right:
        return 0

    res = query(tree, 1, 0, N - 1, left, right)
    return max(
        (right - left + 1) * res[0],
        get_max(tree, N, left, res[1] - 1),
        get_max(tree, N, res[1] + 1, right),
    )


N = int(input())
arr = []

for i in range(N):
    arr.append(int(input()))

tree = [1e9 for i in range(N * 4)]
init(tree, arr, 1, 0, N - 1)

print(get_max(tree, N, 0, N - 1))
