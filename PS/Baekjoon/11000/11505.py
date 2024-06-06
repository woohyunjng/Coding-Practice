from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
        return
    init(tree, arr, node * 2, start, (start + end) // 2)
    init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
    tree[node] = tree[node * 2] * tree[node * 2 + 1] % 1000000007


def query(tree, node, start, end, left, right):
    if right < start or end < left:
        return 1
    elif left <= start and end <= right:
        return tree[node]

    left_mul = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_mul = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return left_mul * right_mul % 1000000007


def update(tree, arr, node, start, end, index, val):
    if index < start or end < index:
        return
    elif start == end:
        tree[node] = val
        arr[index] = val
        return

    update(tree, arr, node * 2, start, (start + end) // 2, index, val)
    update(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = tree[node * 2] * tree[node * 2 + 1] % 1000000007


N, M, K = map(int, stdin.readline().rstrip().split())
tree = [1 for i in range(N * 4)]
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
