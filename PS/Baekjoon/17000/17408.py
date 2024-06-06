from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = [arr[start], 0]
        return

    init(tree, arr, node * 2, start, (start + end) // 2)
    init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
    tree[node] = list(sorted(tree[node * 2] + tree[node * 2 + 1]))[-2:]


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return [0, 0]
    elif left <= start and end <= right:
        return tree[node]

    left_val = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_val = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return list(sorted(left_val + right_val))[-2:]


def update(tree, node, start, end, index, val):
    if index < start or index > end:
        return
    elif start == end:
        tree[node] = [val, 0]
        return

    update(tree, node * 2, start, (start + end) // 2, index, val)
    update(tree, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = list(sorted(tree[node * 2] + tree[node * 2 + 1]))[-2:]


N = int(stdin.readline())
arr = list(map(int, stdin.readline().rstrip().split()))

tree = [[0, 0] for i in range(N * 4)]
init(tree, arr, 1, 0, N - 1)

M = int(stdin.readline())

for i in range(M):
    A, B, C = map(int, stdin.readline().rstrip().split())
    if A == 1:
        update(tree, 1, 0, N - 1, B - 1, C)
    else:
        print(sum(query(tree, 1, 0, N - 1, B - 1, C - 1)))
