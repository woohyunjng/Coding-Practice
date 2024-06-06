from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)


def lazy_update(tree, lazy, node, start, end):
    if start != end:
        lazy[node * 2] = [lazy[node * 2][0] + lazy[node][0], lazy[node * 2][1] + lazy[node][1]]
        lazy[node * 2 + 1] = [
            lazy[node * 2 + 1][0] + lazy[node][0],
            lazy[node * 2 + 1][1] + lazy[node][1],
        ]
    else:
        tree[node] += lazy[node][1] * start - lazy[node][0]

    lazy[node] = [0, 0]


def query(tree, lazy, node, start, end, index):
    lazy_update(tree, lazy, node, start, end)
    if index > end or index < start:
        return 0
    elif start == end and start == index:
        return tree[node]
    else:
        left = query(tree, lazy, node * 2, start, (start + end) // 2, index)
        right = query(tree, lazy, node * 2 + 1, (start + end) // 2 + 1, end, index)
        return left + right


def update(tree, lazy, node, start, end, left, right, val):
    lazy_update(tree, lazy, node, start, end)

    if right < start or left > end:
        return
    if left <= start and end <= right:
        lazy[node] = [lazy[node][0] + val, lazy[node][1] + 1]
        return

    update(tree, lazy, node * 2, start, (start + end) // 2, left, right, val)
    update(tree, lazy, node * 2 + 1, (start + end) // 2 + 1, end, left, right, val)


N = int(stdin.readline())
tree = [0 for i in range(N * 4)]
lazy = [[0, 0] for i in range(N * 4)]

arr = list(map(int, stdin.readline().rstrip().split()))
init(tree, arr, 1, 0, N - 1)

Q = int(stdin.readline())
for i in range(Q):
    inp = list(map(int, stdin.readline().rstrip().split()))
    if inp[0] == 1:
        update(tree, lazy, 1, 0, N - 1, inp[1] - 1, inp[2] - 1, inp[1] - 2)
    else:
        print(query(tree, lazy, 1, 0, N - 1, inp[1] - 1))
