from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = tree[node * 2] + tree[node * 2 + 1]


def query(tree, node, start, end, left, right):
    if right < start or end < left:
        return 0
    elif left <= start and end <= right:
        return tree[node]

    left_min = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_min = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return left_min + right_min


def update(tree, arr, node, start, end, index, val):
    if index < start or index > end:
        return
    if start == end:
        tree[node] = val
        arr[index] = val
        return

    update(tree, arr, node * 2, start, (start + end) // 2, index, val)
    update(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


N = int(stdin.readline())
arr = list(map(lambda x: int(x) % 2, stdin.readline().rstrip().split()))

tree = [0 for i in range(N * 4)]
init(tree, arr, 1, 0, N - 1)

M = int(stdin.readline())
for i in range(M):
    A, B, C = map(int, stdin.readline().rstrip().split())
    if A == 1:
        update(tree, arr, 1, 0, N - 1, B - 1, C % 2)
    elif A == 2:
        print(C - B + 1 - query(tree, 1, 0, N - 1, B - 1, C - 1))
    else:
        print(query(tree, 1, 0, N - 1, B - 1, C - 1))
