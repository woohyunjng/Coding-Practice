from sys import stdin


def get_tup(first, second):
    if first[0] < second[0]:
        return first
    elif first[0] > second[0]:
        return second
    else:
        return (first[0], min(first[1], second[1]))


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = (arr[start], start)
        return

    init(tree, arr, node * 2, start, (start + end) // 2)
    init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
    tree[node] = get_tup(tree[node * 2], tree[node * 2 + 1])


def update(tree, arr, node, start, end, index, value):
    if index < start or end < index:
        return
    elif start == end:
        arr[index] = value
        tree[node] = (value, index)
        return

    update(tree, arr, node * 2, start, (start + end) // 2, index, value)
    update(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end, index, value)
    tree[node] = get_tup(tree[node * 2], tree[node * 2 + 1])


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return (1e12, -1)
    elif left <= start and end <= right:
        return tree[node]

    left_min = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_min = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return get_tup(left_min, right_min)


N = int(stdin.readline())
arr = list(map(int, stdin.readline().rstrip().split()))
tree = [(1e12, -1) for i in range(N * 4)]

init(tree, arr, 1, 0, N - 1)

M = int(stdin.readline())
for i in range(M):
    A, B, C = map(int, stdin.readline().rstrip().split())

    if A == 1:
        update(tree, arr, 1, 0, N - 1, B - 1, C)
    else:
        print(query(tree, 1, 0, N - 1, B - 1, C - 1)[1] + 1)
