from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = tree[node * 2] + tree[node * 2 + 1]


def query(tree, node, start, end, left, right):
    if left > end or right < start:
        return 0
    elif left <= start and end <= right:
        return tree[node]

    left_sum = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_sum = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return left_sum + right_sum


def update(tree, arr, node, start, end, index, val):
    if index < start or index > end:
        return
    if start == end:
        arr[index] = val
        tree[node] = val
        return

    update(tree, arr, node * 2, start, (start + end) // 2, index, val)
    update(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


N, M, K = map(int, stdin.readline().rstrip().split())
tree = [0 for i in range(N * 4)]
arr = []

for i in range(N):
    arr.append(int(stdin.readline().rstrip()))
init(tree, arr, 1, 0, N - 1)

for i in range(M + K):
    A, B, C = map(int, stdin.readline().rstrip().split())
    if A == 1:
        update(tree, arr, 1, 0, N - 1, B - 1, C)
    else:
        print(query(tree, 1, 0, N - 1, B - 1, C - 1))
