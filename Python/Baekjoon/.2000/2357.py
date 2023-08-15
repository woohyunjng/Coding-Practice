from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = (arr[start], arr[start])
        return

    init(tree, arr, node * 2, start, (start + end) // 2)
    init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
    tree[node] = (
        min(tree[node * 2][0], tree[node * 2 + 1][0]),
        max(tree[node * 2][1], tree[node * 2 + 1][1]),
    )


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return (1e9, -1)
    elif left <= start and end <= right:
        return tree[node]

    left_val = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_val = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return (min(left_val[0], right_val[0]), max(left_val[1], right_val[1]))


N, M = map(int, stdin.readline().rstrip().split())
arr = []
tree = [(1e9, -1) for i in range(N * 4)]

for i in range(N):
    arr.append(int(stdin.readline()))
init(tree, arr, 1, 0, N - 1)

for i in range(M):
    A, B = map(int, stdin.readline().rstrip().split())
    print(*query(tree, 1, 0, N - 1, A - 1, B - 1))
