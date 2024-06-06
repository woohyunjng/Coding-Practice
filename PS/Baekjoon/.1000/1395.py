from sys import stdin


def lazy_update(tree, lazy, node, start, end):
    if not lazy[node]:
        return

    tree[node] = end - start + 1 - tree[node]
    if start != end:
        lazy[node * 2] = not lazy[node * 2]
        lazy[node * 2 + 1] = not lazy[node * 2 + 1]
    lazy[node] = False


def query(tree, lazy, node, start, end, left, right):
    lazy_update(tree, lazy, node, start, end)

    if right < start or left > end:
        return 0
    elif left <= start and end <= right:
        return tree[node]

    left_sum = query(tree, lazy, node * 2, start, (start + end) >> 1, left, right)
    right_sum = query(
        tree, lazy, node * 2 + 1, ((start + end) >> 1) + 1, end, left, right
    )
    return left_sum + right_sum


def update(tree, lazy, node, start, end, left, right):
    lazy_update(tree, lazy, node, start, end)

    if right < start or left > end:
        return
    elif left <= start and end <= right:
        lazy[node] = not lazy[node]
        lazy_update(tree, lazy, node, start, end)
        return

    update(tree, lazy, node * 2, start, (start + end) >> 1, left, right)
    update(tree, lazy, node * 2 + 1, ((start + end) >> 1) + 1, end, left, right)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


N, M = map(int, stdin.readline().rstrip().split())
tree = [0 for i in range(N * 4)]
lazy = [False for i in range(N * 4)]

for i in range(M):
    O, S, T = map(int, stdin.readline().rstrip().split())
    if O == 0:
        update(tree, lazy, 1, 1, N, S, T)
    else:
        print(query(tree, lazy, 1, 1, N, S, T))
